#include "StateMenuSFML.h"
#include "StateGameSFML.h"
#include <assert.h>

StateMenuSFML::StateMenuSFML(/* args */) 
{
    
}

StateMenuSFML::StateMenuSFML(std::shared_ptr<Context> &cContext) 
    : context(cContext), isPlayButSelected(true),
      isPlayButPressed(false), isExitButSelected(false),
      isExitButPressed(false)
{
    
}

StateMenuSFML::~StateMenuSFML() 
{
    
}

void StateMenuSFML::Init() 
{
    assert(textFont.loadFromFile("./data/fonts/BebasNeue-Regular.ttf"));
    assert(music.openFromFile("data/sounds/music/01town0.wav"));

    music.play();
    music.setLoop(true);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    // Title
    gameTitle.setFont(textFont);
    gameTitle.setString("Legend of Nautibus");
    gameTitle.setCharacterSize(50);
    gameTitle.setOrigin(gameTitle.getLocalBounds().left+gameTitle.getLocalBounds().width/2.0f,
                        gameTitle.getLocalBounds().top+gameTitle.getLocalBounds().height/2.0f);
    gameTitle.setPosition(winx/2.0f, winy/2.0f - 150);


    ///// BUTTONS
    int butSize = 30;

    // Play Button
    playButton.setFont(textFont);
    playButton.setString("Play");
        playButton.setCharacterSize(butSize);
    playButton.setOrigin(playButton.getLocalBounds().left+playButton.getLocalBounds().width/2.0f,
                        playButton.getLocalBounds().top+playButton.getLocalBounds().height/2.0f);
    playButton.setPosition(winx/2.0f, winy/2.0f - 25.f);

    // Exit Button
    exitButton.setFont(textFont);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(butSize);
    exitButton.setOrigin(exitButton.getLocalBounds().left+exitButton.getLocalBounds().width/2.0f,
                        exitButton.getLocalBounds().top+exitButton.getLocalBounds().height/2.0f);
    exitButton.setPosition(winx/2.0f, winy/2.0f + 25.f);

}

void StateMenuSFML::ProcessInput() 
{
    sf::Event event;
    while (context->renderWin->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                context->renderWin->close();
                context->quit = true;
                break;
            
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                {
                    if (!isPlayButSelected)
                    {
                        isPlayButSelected = true;
                        isExitButSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!isExitButSelected)
                    {
                        isPlayButSelected = false;
                        isExitButSelected = true;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    isPlayButPressed = false;
                    isExitButPressed = false;

                    if (isPlayButSelected)
                    {
                        isPlayButPressed = true;
                    }
                    else
                    {
                        isExitButPressed = true;
                    }

                    break;
                }
                default:
                {
                    break;
                }
                }
            default:
                break;
        }
    }


}

void StateMenuSFML::Update() 
{
    if(isPlayButSelected)
    {
        playButton.setFillColor(sf::Color::Black);
        exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        exitButton.setFillColor(sf::Color::Black);
        playButton.setFillColor(sf::Color::White);
    }
    
    if(isPlayButPressed)
    {
        context->stateMan->Add(std::make_unique<StateGameSFML>(context), true);
    }
    else if(isExitButPressed)
    {
        context->renderWin->close();
        context->quit = true;
    }
}

void StateMenuSFML::Display() 
{
    context->renderWin->clear(sf::Color(50,50,50,255));
    context->renderWin->draw(gameTitle);
    context->renderWin->draw(playButton);
    context->renderWin->draw(exitButton);
    context->renderWin->display();
}

void StateMenuSFML::Pause() 
{
    
}

void StateMenuSFML::Start() 
{
    
}
