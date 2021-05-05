#include "StateMenuSFML.h"
#include "StateGameSFML.h"
#include <assert.h>

StateMenuSFML::StateMenuSFML(/* args */)
{
}

StateMenuSFML::StateMenuSFML(std::shared_ptr<Context> &cContext)
    : context(cContext), isPlayButSelected(true),
      isPlayButPressed(false), isInstructionButSelected(false),
      isInstructionButPressed(false), isInInstructionSubMenu(false),
      isExitButSelected(false), isExitButPressed(false)
{
}

StateMenuSFML::~StateMenuSFML()
{
    music.stop();
}

void StateMenuSFML::Init()
{
    assert(textFont.loadFromFile("./data/fonts/BebasNeue-Regular.ttf"));
    assert(music.openFromFile("data/sounds/music/01town0.wav"));
    assert(buffer.loadFromFile("data/sounds/sfx/menuNav.wav"));

    sound.setBuffer(buffer);

    music.play();
    music.setLoop(true);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    // Title
    gameTitle.setFont(textFont);
    gameTitle.setString("Legend of Nautibus");
    gameTitle.setCharacterSize(50);
    gameTitle.setOrigin(gameTitle.getLocalBounds().left +
                        gameTitle.getLocalBounds().width / 2.0f,
                        gameTitle.getLocalBounds().top + 
                        gameTitle.getLocalBounds().height / 2.0f);
    gameTitle.setPosition(winx / 2.0f, winy / 2.0f - 150);

    ///// BUTTONS
    int butSize = 30;

    // Play Button
    playButton.setFont(textFont);
    playButton.setString("Play");
    playButton.setCharacterSize(butSize);
    playButton.setOrigin(playButton.getLocalBounds().left +
                            playButton.getLocalBounds().width / 2.0f,
                            playButton.getLocalBounds().top + 
                            playButton.getLocalBounds().height / 2.0f);
    playButton.setPosition(winx / 2.0f, winy / 2.0f - 40.f);

    // Instruction Button
    instructionButton.setFont(textFont);
    instructionButton.setString("Instructions");
    instructionButton.setCharacterSize(butSize);
    instructionButton.setOrigin(playButton.getLocalBounds().left +
                            instructionButton.getLocalBounds().width / 2.0f,
                            instructionButton.getLocalBounds().top + 
                            instructionButton.getLocalBounds().height / 2.0f);
    instructionButton.setPosition(winx / 2.0f, winy / 2.0f);

    // Exit Button
    exitButton.setFont(textFont);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(butSize);
    exitButton.setOrigin(exitButton.getLocalBounds().left +
                            exitButton.getLocalBounds().width / 2.0f,
                            exitButton.getLocalBounds().top + 
                            exitButton.getLocalBounds().height / 2.0f);
    exitButton.setPosition(winx / 2.0f, winy / 2.0f + 40.f);

    // Instruction Sub Menu
        // moveText
            moveText.setFont(textFont);
            moveText.setString("Press ZQSD to move");
            moveText.setCharacterSize(butSize);
            moveText.setOrigin(exitButton.getLocalBounds().left +
                                    moveText.getLocalBounds().width / 2.0f,
                                    moveText.getLocalBounds().top + 
                                    moveText.getLocalBounds().height / 2.0f);
            moveText.setPosition(winx / 2.0f, winy / 2.0f - 75.f);

        // attackText
            attackText.setFont(textFont);
            attackText.setString("Left click to attack");
            attackText.setCharacterSize(butSize);
            attackText.setOrigin(exitButton.getLocalBounds().left +
                                    attackText.getLocalBounds().width / 2.0f,
                                    attackText.getLocalBounds().top + 
                                    attackText.getLocalBounds().height / 2.0f);
            attackText.setPosition(winx / 2.0f, winy / 2.0f - 35.f);

            // interactText
            interactText.setFont(textFont);
            interactText.setString("Press E to interact with NPCs");
            interactText.setCharacterSize(butSize);
            interactText.setOrigin(exitButton.getLocalBounds().left +
                                    interactText.getLocalBounds().width / 2.0f,
                                    interactText.getLocalBounds().top + 
                                    interactText.getLocalBounds().height / 2.0f);
            interactText.setPosition(winx / 2.0f, winy / 2.0f + 5.f);

        // pauseText
            pauseText.setFont(textFont);
            pauseText.setString("Press Escape to pause the game");
            pauseText.setCharacterSize(butSize);
            pauseText.setOrigin(exitButton.getLocalBounds().left +
                                    pauseText.getLocalBounds().width / 2.0f,
                                    pauseText.getLocalBounds().top + 
                                    pauseText.getLocalBounds().height / 2.0f);
            pauseText.setPosition(winx / 2.0f, winy / 2.0f + 45.f);

        // debugModeText
            debugModeText.setFont(textFont);
            debugModeText.setString("Press P to display debug mode");
            debugModeText.setCharacterSize(butSize);
            debugModeText.setOrigin(exitButton.getLocalBounds().left +
                                    debugModeText.getLocalBounds().width / 2.0f,
                                    debugModeText.getLocalBounds().top + 
                                    debugModeText.getLocalBounds().height / 2.0f);
            debugModeText.setPosition(winx / 2.0f, winy / 2.0f + 85.f);

        // quitSubMenuText
            quitSubMenuText.setFont(textFont);
            quitSubMenuText.setString("Back");
            quitSubMenuText.setCharacterSize(butSize+10);
            quitSubMenuText.setOrigin(exitButton.getLocalBounds().left +
                                    quitSubMenuText.getLocalBounds().width / 2.0f,
                                    quitSubMenuText.getLocalBounds().top + 
                                    quitSubMenuText.getLocalBounds().height / 2.0f);
            quitSubMenuText.setPosition(60.f, winy - 60.f);
            quitSubMenuText.setFillColor(sf::Color::Black);
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
                if (isExitButSelected)
                {
                    isInstructionButSelected = true;
                    isExitButSelected = false;
                    sound.play();
                }
                else if (isInstructionButSelected && !isInInstructionSubMenu)
                {
                    isPlayButSelected = true;
                    isInstructionButSelected = false;
                    sound.play();
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (isPlayButSelected)
                {
                    isPlayButSelected = false;
                    isInstructionButSelected = true;
                    sound.play();
                }
                else if (isInstructionButSelected && !isInInstructionSubMenu)
                {
                    isInstructionButSelected = false;
                    isExitButSelected = true;
                    sound.play();
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                isPlayButPressed = false;
                isInstructionButPressed = false;
                isExitButPressed = false;

                if (isPlayButSelected)
                {
                    isPlayButPressed = true;
                }
                else if (isInInstructionSubMenu)
                {
                    isInInstructionSubMenu = false;
                    sound.play();
                }
                else if (isInstructionButSelected)
                {
                    isInstructionButPressed = true;
                    sound.play();
                }
                else if (isExitButSelected)
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
    if (isPlayButSelected)
    {
        playButton.setFillColor(sf::Color::Black);
        instructionButton.setFillColor(sf::Color::White);
        exitButton.setFillColor(sf::Color::White);
    }
    else if (isInstructionButSelected)
    {
        instructionButton.setFillColor(sf::Color::Black);
        playButton.setFillColor(sf::Color::White);
        exitButton.setFillColor(sf::Color::White);
    }
        else if (isExitButSelected)
    {
        exitButton.setFillColor(sf::Color::Black);
        playButton.setFillColor(sf::Color::White);
        instructionButton.setFillColor(sf::Color::White);
    }

    if (isPlayButPressed)
    {
        context->stateMan->Add(std::make_unique<StateGameSFML>(context), true);
    }
    else if (isInstructionButPressed)
    {
        isInInstructionSubMenu = true;
    }
    else if (isExitButPressed)
    {
        context->renderWin->close();
        context->quit = true;
    }
}

void StateMenuSFML::Display()
{
    context->renderWin->clear(sf::Color(50, 50, 50, 255));
    context->renderWin->draw(gameTitle);
    if(!isInInstructionSubMenu)
    {
        context->renderWin->draw(playButton);
        context->renderWin->draw(instructionButton);
        context->renderWin->draw(exitButton);
    }else
    {
        context->renderWin->draw(moveText);
        context->renderWin->draw(attackText);
        context->renderWin->draw(interactText);
        context->renderWin->draw(pauseText);
        context->renderWin->draw(debugModeText);
        context->renderWin->draw(quitSubMenuText);
    }

    context->renderWin->display();
}

void StateMenuSFML::Pause()
{
}

void StateMenuSFML::Start()
{
}
