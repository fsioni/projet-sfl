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
    assert(music.openFromFile("data/sounds/music/01town0.wav"));
    assert(buffer.loadFromFile("data/sounds/sfx/menuNav.wav"));

    sound.setBuffer(buffer);

    music.play();
    music.setLoop(true);

    bgSprite.setTexture(context->assetMan->GetTextureBackground());
    bgSprite.setScale(0.5f, 0.5f);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    // Title
    gameTitle.setFont(context->assetMan->GetMainFont());
    gameTitle.setFillColor(context->assetMan->GetMainTextColor());
    gameTitle.setOutlineColor(sf::Color::Black);
    gameTitle.setOutlineThickness(3);
    gameTitle.setString("Legend of Nautibus");
    gameTitle.setCharacterSize(100);
    gameTitle.setOrigin(gameTitle.getLocalBounds().left +
                        gameTitle.getLocalBounds().width / 2.0f,
                        gameTitle.getLocalBounds().top + 
                        gameTitle.getLocalBounds().height / 2.0f);
    gameTitle.setPosition(winx / 2.0f, 235);

    logoSprite.setTexture(context->assetMan->GetTextureLogo());
    logoSprite.setOrigin(logoSprite.getLocalBounds().left +
                            logoSprite.getLocalBounds().width / 2.0f,
                            logoSprite.getLocalBounds().top +
                            logoSprite.getLocalBounds().height / 2.0f);
    logoSprite.setPosition(winx/2, winy/2-150);


    ///// BUTTONS
    int butSize = 50;

    // Play Button
    playButton.setFont(context->assetMan->GetMainFont());
    playButton.setFillColor(context->assetMan->GetMainTextColor());
    playButton.setOutlineColor(sf::Color::Black);
    playButton.setOutlineThickness(3);
    playButton.setString("Play");
    playButton.setCharacterSize(butSize);
    playButton.setOrigin(playButton.getLocalBounds().left +
                            playButton.getLocalBounds().width / 2.0f,
                            playButton.getLocalBounds().top + 
                            playButton.getLocalBounds().height / 2.0f);
    playButton.setPosition(winx / 2.0f, winy / 2.0f + 45.f);

    // Instruction Button
    instructionButton.setFont(context->assetMan->GetMainFont());
    instructionButton.setFillColor(context->assetMan->GetMainTextColor());
    instructionButton.setOutlineColor(sf::Color::Black);
    instructionButton.setOutlineThickness(3);
    instructionButton.setString("Instructions");
    instructionButton.setCharacterSize(butSize);
    instructionButton.setOrigin(playButton.getLocalBounds().left +
                            instructionButton.getLocalBounds().width / 2.0f,
                            instructionButton.getLocalBounds().top + 
                            instructionButton.getLocalBounds().height / 2.0f);
    instructionButton.setPosition(winx / 2.0f, winy / 2.0f + 105);

    // Exit Button
    exitButton.setFont(context->assetMan->GetMainFont());
    exitButton.setFillColor(context->assetMan->GetMainTextColor());
    exitButton.setOutlineColor(sf::Color::Black);
    exitButton.setOutlineThickness(3);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(butSize);
    exitButton.setOrigin(exitButton.getLocalBounds().left +
                            exitButton.getLocalBounds().width / 2.0f,
                            exitButton.getLocalBounds().top + 
                            exitButton.getLocalBounds().height / 2.0f);
    exitButton.setPosition(winx / 2.0f, winy / 2.0f + 165.f);

    // Instruction Sub Menu
        // moveText
            moveText.setFont(context->assetMan->GetMainFont());
            moveText.setFillColor(context->assetMan->GetMainTextColor());
            moveText.setOutlineColor(sf::Color::Black);
            moveText.setOutlineThickness(2);
            moveText.setString("Press  ZQSD  to  move");
            moveText.setCharacterSize(butSize);
            moveText.setOrigin(exitButton.getLocalBounds().left +
                                    moveText.getLocalBounds().width / 2.0f,
                                    moveText.getLocalBounds().top + 
                                    moveText.getLocalBounds().height / 2.0f);
            moveText.setPosition(winx / 2.0f, winy / 2.0f - 120.f);

        // attackText
            attackText.setFont(context->assetMan->GetMainFont());
            attackText.setFillColor(context->assetMan->GetMainTextColor());
            attackText.setOutlineColor(sf::Color::Black);
            attackText.setOutlineThickness(2);
            attackText.setString("Left  click  to  attack");
            attackText.setCharacterSize(butSize);
            attackText.setOrigin(exitButton.getLocalBounds().left +
                                    attackText.getLocalBounds().width / 2.0f,
                                    attackText.getLocalBounds().top + 
                                    attackText.getLocalBounds().height / 2.0f);
            attackText.setPosition(winx / 2.0f, winy / 2.0f - 60.f);

            // interactText
            interactText.setFont(context->assetMan->GetMainFont());
            interactText.setFillColor(context->assetMan->GetMainTextColor());
            interactText.setOutlineColor(sf::Color::Black);
            interactText.setOutlineThickness(2);
            interactText.setString("Press  E  to  interact  with  NPCs");
            interactText.setCharacterSize(butSize);
            interactText.setOrigin(exitButton.getLocalBounds().left +
                                    interactText.getLocalBounds().width / 2.0f,
                                    interactText.getLocalBounds().top + 
                                    interactText.getLocalBounds().height / 2.0f);
            interactText.setPosition(winx / 2.0f, winy / 2.0f);

        // pauseText
            pauseText.setFont(context->assetMan->GetMainFont());
            pauseText.setFillColor(context->assetMan->GetMainTextColor());
            pauseText.setOutlineColor(sf::Color::Black);
            pauseText.setOutlineThickness(2);
            pauseText.setString("Press  Escape  to  pause  the  game");
            pauseText.setCharacterSize(butSize);
            pauseText.setOrigin(exitButton.getLocalBounds().left +
                                    pauseText.getLocalBounds().width / 2.0f,
                                    pauseText.getLocalBounds().top + 
                                    pauseText.getLocalBounds().height / 2.0f);
            pauseText.setPosition(winx / 2.0f, winy / 2.0f + 60.f);

        // debugModeText
            debugModeText.setFont(context->assetMan->GetMainFont());
            debugModeText.setFillColor(context->assetMan->GetMainTextColor());
            debugModeText.setOutlineColor(sf::Color::Black);
            debugModeText.setOutlineThickness(2);
            debugModeText.setString("Press  P  to  display  debug  mode");
            debugModeText.setCharacterSize(butSize);
            debugModeText.setOrigin(exitButton.getLocalBounds().left +
                                    debugModeText.getLocalBounds().width / 2.0f,
                                    debugModeText.getLocalBounds().top + 
                                    debugModeText.getLocalBounds().height / 2.0f);
            debugModeText.setPosition(winx / 2.0f, winy / 2.0f + 120.f);

        // quitSubMenuText
            quitSubMenuText.setFont(context->assetMan->GetMainFont());
            quitSubMenuText.setFillColor(sf::Color::White);
            quitSubMenuText.setOutlineColor(sf::Color::Black);
            quitSubMenuText.setOutlineThickness(2);
            quitSubMenuText.setString("Back");
            quitSubMenuText.setCharacterSize(butSize+10);
            quitSubMenuText.setOrigin(exitButton.getLocalBounds().left +
                                    quitSubMenuText.getLocalBounds().width / 2.0f,
                                    quitSubMenuText.getLocalBounds().top + 
                                    quitSubMenuText.getLocalBounds().height / 2.0f);
            quitSubMenuText.setPosition(60.f, winy - 40.f);
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
            
            case sf::Keyboard::Z:
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

            case sf::Keyboard::Down:
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

            case sf::Keyboard::S :
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

            case sf::Keyboard::M:
                context->isMute = !(context->isMute);
                break;

            case sf::Keyboard::Return:
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

            default:
                break;
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
        playButton.setFillColor(sf::Color::White);
        playButton.setOutlineColor(sf::Color::Black);
        instructionButton.setFillColor(context->assetMan->GetMainTextColor());
        instructionButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
    }
    else if (isInstructionButSelected)
    {
        instructionButton.setFillColor(sf::Color::White);
        instructionButton.setOutlineColor(sf::Color::Black);
        playButton.setFillColor(context->assetMan->GetMainTextColor());
        playButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
    }
        else if (isExitButSelected)
    {
        exitButton.setFillColor(sf::Color::White);
        exitButton.setOutlineColor(sf::Color::Black);
        playButton.setFillColor(context->assetMan->GetMainTextColor());
        playButton.setOutlineColor(sf::Color::Black);
        instructionButton.setFillColor(context->assetMan->GetMainTextColor());
        instructionButton.setOutlineColor(sf::Color::Black);
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

    if (context->isMute && (music.getVolume() != 0 || sound.getVolume() != 0))
    {
        music.setVolume(0);
        sound.setVolume(0);
    }
    
    if (!context->isMute && (music.getVolume() == 0 || sound.getVolume() != 0))
    {
        music.setVolume(70);
        sound.setVolume(100);
    }
}

void StateMenuSFML::Display()
{
    context->renderWin->clear(sf::Color(1, 31, 75));
    context->renderWin->draw(bgSprite);

    if(!isInInstructionSubMenu)
    {
        context->renderWin->draw(logoSprite);
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
