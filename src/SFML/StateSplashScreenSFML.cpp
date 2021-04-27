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

    gameText.setFont(textFont);
    madeByText.setFont(textFont);

    gameText.setString("Legend Of Nautibus");
    madeByText.setString("Made by :\nSIONI Fares\nBAGNOl Stanislas\nCHOUGAR Lyes");

    gameText.setCharacterSize(90);
    madeByText.setCharacterSize(36);

    gameText.setFillColor(sf::Color::White);
    madeByText.setFillColor(sf::Color::White);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    gameText.setPosition(winx/2.0f, winy/2.0f);
    madeByText.setPosition(winx/2.0f, winy /2.0f + 200.0f);

    gameText.setOrigin(gameText.getLocalBounds().left+gameText.getLocalBounds().width/2.0f,
                        gameText.getLocalBounds().top+gameText.getLocalBounds().height/2.0f);

    madeByText.setOrigin(madeByText.getLocalBounds().left+madeByText.getLocalBounds().width/2.0f,
                        madeByText.getLocalBounds().top+madeByText.getLocalBounds().height/2.0f);
    
    gameText.setStyle(sf::Text::Bold);

    start = std::clock();

}

void StateSplashScreenSFML::ProcessInput() 
{
    sf::Event Event;
    while(context->renderWin->pollEvent(Event)){
            
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
                context->stateMan->Add(std::make_unique<StateMenuSFML>(context), true);
                break;
            
            case sf::Keyboard::Enter:
                context->stateMan->Add(std::make_unique<StateMenuSFML>(context), true);
                break;

            case sf::Keyboard::X:
                context->renderWin->close();  
                context->quit = true;
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
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    if (duration > 1)
    {
        context->stateMan->Add(make_unique<StateMenuSFML>(context), true);
    }
}

void StateSplashScreenSFML::Display() 
{
    context->renderWin->clear();
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
