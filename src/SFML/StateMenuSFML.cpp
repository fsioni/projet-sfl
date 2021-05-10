#include "StateMenuSFML.h"
#include "StateGameSFML.h"
#include <assert.h>

StateMenuSFML::StateMenuSFML(/* args */)
{
}

StateMenuSFML::StateMenuSFML(std::shared_ptr<Context> &cContext)
    : context(cContext), isSoundButSelected(false), isSoundButPressed(false),
     isPlayButSelected(true), isPlayButPressed(false),
     isInstructionButSelected(false), isInstructionButPressed(false),
     isInInstructionSubMenu(false), isExitButSelected(false),
     isExitButPressed(false)
{
}

StateMenuSFML::~StateMenuSFML()
{
    music.stop();
}

void StateMenuSFML::Init()
{
    assert(music.openFromFile("data/sounds/music/01town0.wav"));

    sound.setBuffer(context->assetMan->GetSoundBuffers()[0]);

    music.play();
    music.setLoop(true);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    bgSprite.setTexture(context->assetMan->GetTextureBackground());
    bgSprite.setScale(0.5f, 0.5f);

    soundSprite.setTexture(context->assetMan->GetTextureSound());
    soundSprite.setOrigin(soundSprite.getLocalBounds().left +
                        soundSprite.getLocalBounds().width / 2.0f,
                        soundSprite.getLocalBounds().top +
                        soundSprite.getLocalBounds().height / 2.0f);
    soundSprite.setScale(0.5f, 0.5f);
    soundSprite.setPosition(winx-50, 50);


    // Title
    menuTitle.setFont(context->assetMan->GetMainFont());
    menuTitle.setFillColor(context->assetMan->GetMainTextColor());
    menuTitle.setOutlineColor(sf::Color::Black);
    menuTitle.setOutlineThickness(3);
    menuTitle.setString("Menu");
    menuTitle.setCharacterSize(50);
    menuTitle.setOrigin(menuTitle.getLocalBounds().left +
                        menuTitle.getLocalBounds().width / 2.0f,
                        menuTitle.getLocalBounds().top + 
                        menuTitle.getLocalBounds().height / 2.0f);
    menuTitle.setPosition(winx / 2.0f, winy - 50);

    logoSprite.setTexture(context->assetMan->GetTextureLogo());
    logoSprite.setOrigin(logoSprite.getLocalBounds().left +
                            logoSprite.getLocalBounds().width / 2.0f,
                            logoSprite.getLocalBounds().top +
                            logoSprite.getLocalBounds().height / 2.0f);
    logoSprite.setPosition(winx/2, winy/2 - 150);


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

    handCursor.loadFromSystem(sf::Cursor::Hand);
    pointCursor.loadFromSystem(sf::Cursor::Arrow);
}

void StateMenuSFML::ProcessInput()
{
    sf::Event event;
    while (context->renderWin->pollEvent(event))
    {
        if(event.type == sf::Event::Resized){
            context->renderWin->setView(sf::View(
                sf::FloatRect(0, 0, event.size.width, event.size.height)));
            int winX = context->renderWin->getSize().x;
            int winY = context->renderWin->getSize().y;
            soundSprite.setPosition(winX-50, 50);
            logoSprite.setPosition(winX/2, winY/2-150);
            playButton.setPosition(winX / 2.0f, winY / 2.0f + 45.f);
            pauseText.setPosition(winX / 2.0f, winY - 50);
            instructionButton.setPosition(winX / 2.0f, winY / 2.0f + 105);
            exitButton.setPosition(winX / 2.0f, winY / 2.0f + 165.f);
            menuTitle.setPosition(winX / 2.0f, winY - 50);

            quitSubMenuText.setPosition(60.f, winY - 40.f);
            debugModeText.setPosition(winX / 2.0f, winY / 2.0f + 120.f);
            pauseText.setPosition(winX / 2.0f, winY / 2.0f + 60.f);
            interactText.setPosition(winX / 2.0f, winY / 2.0f);
            attackText.setPosition(winX / 2.0f, winY / 2.0f - 60.f);
            moveText.setPosition(winX / 2.0f, winY / 2.0f - 120.f);
        }


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
                else if (isPlayButSelected)
                {
                    isPlayButSelected = false;
                    isSoundButSelected = true;
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
                else if (isPlayButSelected)
                {
                    isPlayButSelected = false;
                    isSoundButSelected = true;
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
                else if (isSoundButSelected)
                {
                    isPlayButSelected = true;
                    isSoundButSelected = false;
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
                else if (isSoundButSelected)
                {
                    isPlayButSelected = true;
                    isSoundButSelected = false;
                }
                break;            

            case sf::Keyboard::Return:
                OnClick();
                break;

            default:
                break;
            }
        default:
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                OnClick();
            }
            break;
        }
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(*context->renderWin.get());
    context->renderWin->setMouseCursor(pointCursor);

    // Bouton Son
    sf::IntRect button(soundSprite.getPosition().x-
        soundSprite.getGlobalBounds().width/2, soundSprite.getPosition().y-
        soundSprite.getGlobalBounds().height/2, soundSprite.getGlobalBounds().width,
        soundSprite.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isPlayButSelected = false;
        isInstructionButSelected = false;
        isExitButSelected = false;
        isSoundButSelected = true;
        context->renderWin->setMouseCursor(handCursor);
    }

    // Bouton Jouer
    button = sf::IntRect(playButton.getPosition().x-
        playButton.getGlobalBounds().width/2, playButton.getPosition().y-
        playButton.getGlobalBounds().height/2, playButton.getGlobalBounds().width,
        playButton.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isPlayButSelected = true;
        isInstructionButSelected = false;
        isExitButSelected = false;
        isSoundButSelected = false;
        context->renderWin->setMouseCursor(handCursor);
    }
    
    // Bouton Instructions
    button = sf::IntRect(instructionButton.getPosition().x-
        instructionButton.getGlobalBounds().width/2, instructionButton.getPosition().y-
        instructionButton.getGlobalBounds().height/2, instructionButton.getGlobalBounds().width,
        instructionButton.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isPlayButSelected = false;
        isInstructionButSelected = true;
        isExitButSelected = false;
        isSoundButSelected = false;
        context->renderWin->setMouseCursor(handCursor);
    }

    // Bouton Retour
    button = sf::IntRect(quitSubMenuText.getPosition().x-
        quitSubMenuText.getGlobalBounds().width/2, quitSubMenuText.getPosition().y-
        quitSubMenuText.getGlobalBounds().height/2, quitSubMenuText.getGlobalBounds().width,
        quitSubMenuText.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        context->renderWin->setMouseCursor(handCursor);
    }
    
    // Bouton Quitter
    button = sf::IntRect(exitButton.getPosition().x-
        exitButton.getGlobalBounds().width/2, exitButton.getPosition().y-
        exitButton.getGlobalBounds().height/2, exitButton.getGlobalBounds().width,
        exitButton.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isPlayButSelected = false;
        isInstructionButSelected = false;
        isExitButSelected = true;
        isSoundButSelected = false;
        context->renderWin->setMouseCursor(handCursor);
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
        soundSprite.setColor(sf::Color::Black);
    }
    else if (isInstructionButSelected)
    {
        instructionButton.setFillColor(sf::Color::White);
        instructionButton.setOutlineColor(sf::Color::Black);
        playButton.setFillColor(context->assetMan->GetMainTextColor());
        playButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::Black);
    }
    else if (isExitButSelected)
    {
        exitButton.setFillColor(sf::Color::White);
        exitButton.setOutlineColor(sf::Color::Black);
        playButton.setFillColor(context->assetMan->GetMainTextColor());
        playButton.setOutlineColor(sf::Color::Black);
        instructionButton.setFillColor(context->assetMan->GetMainTextColor());
        instructionButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::Black);
    }
    else if (isSoundButSelected)
    {
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
        playButton.setFillColor(context->assetMan->GetMainTextColor());
        playButton.setOutlineColor(sf::Color::Black);
        instructionButton.setFillColor(context->assetMan->GetMainTextColor());
        instructionButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::White);
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
    else if (isSoundButPressed)
    {
        isSoundButPressed = false;
        context->isMute = !(context->isMute); 
    }

    if (context->isMute && (music.getVolume() != 0 || sound.getVolume() != 0))
    {
        music.setVolume(0);
        sound.setVolume(0);
        soundSprite.setTextureRect(sf::IntRect(0, 0, 75, 128));
    }
    
    if (!context->isMute && (music.getVolume() == 0 || sound.getVolume() == 0))
    {
        music.setVolume(70);
        sound.setVolume(100);
        soundSprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    }


}

void StateMenuSFML::Display()
{
    context->renderWin->clear(sf::Color(1, 31, 75));
    context->renderWin->draw(bgSprite);

    if(!isInInstructionSubMenu)
    {
        context->renderWin->draw(menuTitle);
        context->renderWin->draw(logoSprite);
        context->renderWin->draw(soundSprite);
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
    music.stop();
}

void StateMenuSFML::Start()
{
    music.play();
}

void StateMenuSFML::OnClick() 
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
    else if (isSoundButSelected)
    {
        isSoundButPressed = true;
        sound.play();
    }
}
