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
    assert(textFont.loadFromFile("./data/fonts/BebasNeue-Regular.ttf"));
    assert(music.openFromFile("data/sounds/music/14entranceNL.wav"));
    assert(bgTex.loadFromFile("data/textures/UI/menuBackground.png"));
    textColor = sf::Color(245, 222, 92);

    music.play();

    bgSprite.setTexture(bgTex);
    bgSprite.setScale(0.5f, 0.5f);

    gameText.setFont(textFont);
    madeByText.setFont(textFont);

    gameText.setFillColor(textColor);
    gameText.setOutlineColor(sf::Color::Black);
    gameText.setOutlineThickness(3);

    madeByText.setFillColor(textColor);
    madeByText.setOutlineColor(sf::Color::Black);
    madeByText.setOutlineThickness(2);

    gameText.setString("Legend Of Nautibus");
    madeByText.setString("Made by :\nSIONI Fares\nBAGNOl Stanislas\nCHOUGAR Lyes");

    gameText.setCharacterSize(100);
    madeByText.setCharacterSize(36);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    gameText.setOrigin(gameText.getLocalBounds().left + 
                        gameText.getLocalBounds().width / 2.0f,
                        gameText.getLocalBounds().top + 
                        gameText.getLocalBounds().height / 2.0f);

    madeByText.setOrigin(madeByText.getLocalBounds().left +
                            madeByText.getLocalBounds().width / 2.0f,
                            madeByText.getLocalBounds().top +
                            madeByText.getLocalBounds().height / 2.0f);

    gameText.setPosition(winx / 2.0f, 235);
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
    context->renderWin->draw(gameText);
    context->renderWin->draw(madeByText);

    context->renderWin->display();
}

void StateSplashScreenSFML::Pause()
{
}

void StateSplashScreenSFML::Start()
{
}
