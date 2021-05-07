#include "StateSplashScreenSFML.h"
#include "StateMenuSFML.h"
#include <assert.h>

StateSplashScreenSFML::StateSplashScreenSFML(/* args */)
{
}

StateSplashScreenSFML::StateSplashScreenSFML(std::shared_ptr<Context> &cContext)
    : context(cContext)
{
}

StateSplashScreenSFML::~StateSplashScreenSFML()
{
}

void StateSplashScreenSFML::Init()
{
    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    assert(music.openFromFile("data/sounds/music/14entranceNL.wav"));

    music.play();

    bgSprite.setTexture(context->assetMan->GetTextureBackground());
    bgSprite.setScale(0.5f, 0.5f);

    logoSprite.setTexture(context->assetMan->GetTextureLogo());
    logoSprite.setOrigin(logoSprite.getLocalBounds().left +
                            logoSprite.getLocalBounds().width / 2.0f,
                            logoSprite.getLocalBounds().top +
                            logoSprite.getLocalBounds().height / 2.0f);
    logoSprite.setPosition(winx/2, winy/2-150);

    madeByText.setFont(context->assetMan->GetMainFont());
    madeByText.setFillColor(context->assetMan->GetMainTextColor());
    madeByText.setOutlineColor(sf::Color::Black);
    madeByText.setOutlineThickness(2);
    madeByText.setString("Made by :\nSIONI Fares\nBAGNOl Stanislas\nCHOUGAR Lyes");
    madeByText.setCharacterSize(36);
    madeByText.setOrigin(madeByText.getLocalBounds().left +
                            madeByText.getLocalBounds().width / 2.0f,
                            madeByText.getLocalBounds().top +
                            madeByText.getLocalBounds().height / 2.0f);
    madeByText.setPosition(150, winy / 2.0f + 200.0f);

    start = std::clock();
}

void StateSplashScreenSFML::ProcessInput()
{
    sf::Event Event;
    while (context->renderWin->pollEvent(Event))
    {

        switch (Event.type)
        {
        case sf::Event::Closed:
            context->renderWin->close();
            context->quit = true;
            break;

        case sf::Event::KeyPressed:
            switch (Event.key.code)
            {
            case sf::Keyboard::Space:
                context->stateMan->
                    Add(std::make_unique<StateMenuSFML>(context), true);
                break;

            case sf::Keyboard::Enter:
                context->stateMan->
                    Add(std::make_unique<StateMenuSFML>(context), true);
                break;

            case sf::Keyboard::X:
                context->renderWin->close();
                context->quit = true;
                break;

            case sf::Keyboard::M:
                context->isMute = !(context->isMute);
                break;

            case sf::Keyboard::Escape:
                context->renderWin->close();
                context->quit = true;
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}

void StateSplashScreenSFML::Update()
{
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    if (duration > 2)
    {
        context->stateMan->Add(std::make_unique<StateMenuSFML>(context), true);
    }

    if (context->isMute && music.getVolume() != 0)
    {
        music.setVolume(0);
    }
    
    if (!context->isMute && music.getVolume() == 0)
    {
        music.setVolume(70);
    }
}

void StateSplashScreenSFML::Display()
{
    context->renderWin->clear(sf::Color(1, 31, 75));
    context->renderWin->draw(bgSprite);
    context->renderWin->draw(logoSprite);
    context->renderWin->draw(madeByText);

    context->renderWin->display();
}

void StateSplashScreenSFML::Pause()
{
}

void StateSplashScreenSFML::Start()
{
}
