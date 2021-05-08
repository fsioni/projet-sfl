#include "StatePauseSFML.h"
#include "StateGameSFML.h"
#include "StateMenuSFML.h"
#include <assert.h>

StatePauseSFML::StatePauseSFML(/* args */)
{
}

StatePauseSFML::StatePauseSFML(std::shared_ptr<Context> &cContext)
    : context(cContext), isSoundButSelected(false), isSoundButPressed(false),
    isResumeButSelected(true), isResumeButPressed(false),
    isMenuButSelected(false), isMenuButPressed(false), isExitButSelected(false),
    isExitButPressed(false)
{
}

StatePauseSFML::~StatePauseSFML()
{
}

void StatePauseSFML::Init()
{
    assert(buffer.loadFromFile("data/sounds/sfx/menuNav.wav"));

    sound.setBuffer(buffer);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    soundSprite.setTexture(context->assetMan->GetTextureSound());
    soundSprite.setOrigin(soundSprite.getLocalBounds().left +
                        soundSprite.getLocalBounds().width / 2.0f,
                        soundSprite.getLocalBounds().top +
                        soundSprite.getLocalBounds().height / 2.0f);
    soundSprite.setScale(0.5f, 0.5f);
    soundSprite.setPosition(winx-50, 50);

    bgSprite.setTexture(context->assetMan->GetTextureBackground());
    bgSprite.setScale(0.5f, 0.5f);

    logoSprite.setTexture(context->assetMan->GetTextureLogo());
    logoSprite.setOrigin(logoSprite.getLocalBounds().left +
                            logoSprite.getLocalBounds().width / 2.0f,
                            logoSprite.getLocalBounds().top +
                            logoSprite.getLocalBounds().height / 2.0f);
    logoSprite.setPosition(winx/2, winy/2-150);

    pauseText.setFont(context->assetMan->GetMainFont());
    pauseText.setFillColor(context->assetMan->GetMainTextColor());
    pauseText.setOutlineColor(sf::Color::Black);
    pauseText.setOutlineThickness(2);
    pauseText.setString("PAUSE");
    pauseText.setCharacterSize(50);
    pauseText.setOrigin(pauseText.getLocalBounds().left + 
                        pauseText.getLocalBounds().width / 2.0f,
                        pauseText.getLocalBounds().top +
                        pauseText.getLocalBounds().height / 2.0f);
    pauseText.setPosition(winx / 2.0f, winy - 50);

    ///// BUTTONS
    int butSize = 50;

    // Play Button
    resumeButton.setFont(context->assetMan->GetMainFont());
    resumeButton.setFillColor(context->assetMan->GetMainTextColor());
    resumeButton.setOutlineColor(sf::Color::Black);
    resumeButton.setOutlineThickness(3);
    resumeButton.setString("Resume");
    resumeButton.setCharacterSize(butSize);
    resumeButton.setOrigin(resumeButton.getLocalBounds().left +
                            resumeButton.getLocalBounds().width / 2.0f,
                            resumeButton.getLocalBounds().top + 
                            resumeButton.getLocalBounds().height / 2.0f);
    resumeButton.setPosition(winx / 2.0f, winy / 2.0f + 45.f);

    // Instruction Button
    menuButton.setFont(context->assetMan->GetMainFont());
    menuButton.setFillColor(context->assetMan->GetMainTextColor());
    menuButton.setOutlineColor(sf::Color::Black);
    menuButton.setOutlineThickness(3);
    menuButton.setString("Menu");
    menuButton.setCharacterSize(butSize);
    menuButton.setOrigin(menuButton.getLocalBounds().left +
                            menuButton.getLocalBounds().width / 2.0f,
                            menuButton.getLocalBounds().top + 
                            menuButton.getLocalBounds().height / 2.0f);
    menuButton.setPosition(winx / 2.0f, winy / 2.0f + 105);

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

    handCursor.loadFromSystem(sf::Cursor::Hand);
    pointCursor.loadFromSystem(sf::Cursor::Arrow);
}

void StatePauseSFML::ProcessInput()
{
    sf::Event event;

    while (context->renderWin->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->renderWin->close();
            context->quit = true;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            OnClick();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                    if (isExitButSelected)
                    {
                        isMenuButSelected = true;
                        isExitButSelected = false;
                        sound.play();
                    }
                    else if (isMenuButSelected)
                    {
                        isResumeButSelected = true;
                        isMenuButSelected = false;
                        sound.play();
                    }
                    else if (isResumeButSelected)
                    {
                        isResumeButSelected = false;
                        isSoundButSelected = true;
                    }
                break;
                
                case sf::Keyboard::Z:
                    if (isExitButSelected)
                    {
                        isMenuButSelected = true;
                        isExitButSelected = false;
                        sound.play();
                    }
                    else if (isMenuButSelected)
                    {
                        isResumeButSelected = true;
                        isMenuButSelected = false;
                        sound.play();
                    }
                    else if (isResumeButSelected)
                    {
                        isResumeButSelected = false;
                        isSoundButSelected = true;
                    }
                break;            

                case sf::Keyboard::Down:
                    if (isResumeButSelected)
                    {
                        isResumeButSelected = false;
                        isMenuButSelected = true;
                        sound.play();
                    }
                    else if (isMenuButSelected)
                    {
                        isMenuButSelected = false;
                        isExitButSelected = true;
                        sound.play();
                    }
                    else if (isSoundButSelected)
                    {
                        isResumeButSelected = true;
                        isSoundButSelected = false;
                    }
                break;

                case sf::Keyboard::S :
                    if (isResumeButSelected)
                    {
                        isResumeButSelected = false;
                        isMenuButSelected = true;
                        sound.play();
                    }
                    else if (isMenuButSelected)
                    {
                        isMenuButSelected = false;
                        isExitButSelected = true;
                        sound.play();
                    }
                    else if (isSoundButSelected)
                    {
                        isResumeButSelected = true;
                        isSoundButSelected = false;
                    }
                break;

                case sf::Keyboard::Return:
                    OnClick();
                break;

                case sf::Keyboard::Escape:
                    context->stateMan->PopCurrent();
                break;
                
                case sf::Keyboard::M:
                    context->isMute = !(context->isMute);
                break;

                default:
                break;
            }
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
        isResumeButSelected = false;
        isExitButSelected = false;
        isSoundButSelected = true;
        context->renderWin->setMouseCursor(handCursor);
    }

    // Bouton Reprendre
        button = sf::IntRect(resumeButton.getPosition().x-
        resumeButton.getGlobalBounds().width/2, resumeButton.getPosition().y-
        resumeButton.getGlobalBounds().height/2, resumeButton.getGlobalBounds().width,
        resumeButton.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isResumeButSelected = true;
        isMenuButSelected = false;
        isExitButSelected = false;
        isSoundButSelected = false;
        context->renderWin->setMouseCursor(handCursor);
    }
    
    // Bouton Instructions
    button = sf::IntRect(menuButton.getPosition().x-
        menuButton.getGlobalBounds().width/2, menuButton.getPosition().y-
        menuButton.getGlobalBounds().height/2, menuButton.getGlobalBounds().width,
        menuButton.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isResumeButSelected = false;
        isMenuButSelected = true;
        isExitButSelected = false;
        isSoundButSelected = false;
        context->renderWin->setMouseCursor(handCursor);
    }
    
    // Bouton Quitter
    button = sf::IntRect(exitButton.getPosition().x-
        exitButton.getGlobalBounds().width/2, exitButton.getPosition().y-
        exitButton.getGlobalBounds().height/2, exitButton.getGlobalBounds().width,
        exitButton.getGlobalBounds().height);

    if (button.contains(mousePos))
    {
        isResumeButSelected = false;
        isMenuButSelected = false;
        isExitButSelected = true;
        isSoundButSelected = false;
        context->renderWin->setMouseCursor(handCursor);
    }
}

void StatePauseSFML::Update()
{
    if (isResumeButSelected)
    {
        resumeButton.setFillColor(sf::Color::White);
        resumeButton.setOutlineColor(sf::Color::Black);
        menuButton.setFillColor(context->assetMan->GetMainTextColor());
        menuButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::Black);
    }
    else if (isMenuButSelected)
    {
        menuButton.setFillColor(sf::Color::White);
        menuButton.setOutlineColor(sf::Color::Black);
        resumeButton.setFillColor(context->assetMan->GetMainTextColor());
        resumeButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::Black);
    }
    else if (isExitButSelected)
    {
        exitButton.setFillColor(sf::Color::White);
        exitButton.setOutlineColor(sf::Color::Black);
        resumeButton.setFillColor(context->assetMan->GetMainTextColor());
        resumeButton.setOutlineColor(sf::Color::Black);
        menuButton.setFillColor(context->assetMan->GetMainTextColor());
        menuButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::Black);
    }
    else if (isSoundButSelected)
    {
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
        resumeButton.setFillColor(context->assetMan->GetMainTextColor());
        resumeButton.setOutlineColor(sf::Color::Black);
        soundSprite.setColor(sf::Color::White);
    }

    if (isResumeButPressed)
    {
        context->stateMan->PopCurrent();
    }
    else if (isMenuButPressed)
    {
        context->stateMan->Add(std::make_unique<StateMenuSFML>(context), true);
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

    if (context->isMute && (sound.getVolume() != 0))
    {
        sound.setVolume(0);
        soundSprite.setTextureRect(sf::IntRect(0, 0, 75, 128));
    }
    
    if (!context->isMute && (sound.getVolume() == 0))
    {
        sound.setVolume(100);
        soundSprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    }
}

void StatePauseSFML::Display()
{
    context->renderWin->draw(bgSprite);
    context->renderWin->draw(logoSprite);
    context->renderWin->draw(soundSprite);
    context->renderWin->draw(pauseText);
    context->renderWin->draw(resumeButton);
    context->renderWin->draw(menuButton);
    context->renderWin->draw(exitButton);
    context->renderWin->display();
}

void StatePauseSFML::Pause()
{
}

void StatePauseSFML::Start()
{
}

void StatePauseSFML::OnClick() 
{
    isResumeButPressed = false;
    isMenuButPressed = false;
    isExitButPressed = false;

    if (isResumeButSelected)
    {
        isResumeButPressed = true;
    }
    else if (isMenuButSelected)
    {
        isMenuButPressed = true;
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
