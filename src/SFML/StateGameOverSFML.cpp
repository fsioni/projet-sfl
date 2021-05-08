#include "StateGameOverSFML.h"
#include "StateGameSFML.h"
#include "StateMenuSFML.h"
#include <assert.h>

StateGameOverSFML::StateGameOverSFML(/* args */)
{
}

StateGameOverSFML::StateGameOverSFML(std::shared_ptr<Context> &cContext)
    : context(cContext), isRestartButSelected(true), isRestartButPressed(false),
    isMenuButSelected(false), isMenuButPressed(false), isExitButSelected(false),
    isExitButPressed(false)
{
}

StateGameOverSFML::~StateGameOverSFML()
{
}

void StateGameOverSFML::Init()
{
    assert(buffer.loadFromFile("data/sounds/sfx/menuNav.wav"));

    sound.setBuffer(buffer);

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;
    assert(music.openFromFile("data/sounds/music/13gameover1V1NL.wav"));

    music.play();

    bgSprite.setTexture(context->assetMan->GetTextureBackground());
    bgSprite.setScale(0.5f, 0.5f);
    logoSprite.setTexture(context->assetMan->GetTextureLogo());
    logoSprite.setOrigin(logoSprite.getLocalBounds().left +
                            logoSprite.getLocalBounds().width / 2.0f,
                            logoSprite.getLocalBounds().top +
                            logoSprite.getLocalBounds().height / 2.0f);
    logoSprite.setPosition(winx/2, winy/2-150);

    gameOverText.setFont(context->assetMan->GetMainFont());
    gameOverText.setFillColor(context->assetMan->GetMainTextColor());
    gameOverText.setOutlineColor(sf::Color::Black);
    gameOverText.setOutlineThickness(2);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(50);
    gameOverText.setOrigin(gameOverText.getLocalBounds().left + 
                            gameOverText.getLocalBounds().width / 2.0f,
                            gameOverText.getLocalBounds().top + 
                            gameOverText.getLocalBounds().height / 2.0f);
    gameOverText.setPosition(winx / 2.0f, winy - 50);

   ///// BUTTONS
    int butSize = 50;

    // Play Button
    restartButton.setFont(context->assetMan->GetMainFont());
    restartButton.setFillColor(context->assetMan->GetMainTextColor());
    restartButton.setOutlineColor(sf::Color::Black);
    restartButton.setOutlineThickness(3);
    restartButton.setString("Restart");
    restartButton.setCharacterSize(butSize);
    restartButton.setOrigin(restartButton.getLocalBounds().left +
                            restartButton.getLocalBounds().width / 2.0f,
                            restartButton.getLocalBounds().top + 
                            restartButton.getLocalBounds().height / 2.0f);
    restartButton.setPosition(winx / 2.0f, winy / 2.0f + 45.f);

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
}

void StateGameOverSFML::ProcessInput()
{
    sf::Event event;

    while (context->renderWin->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->renderWin->close();
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
                        isRestartButSelected = true;
                        isMenuButSelected = false;
                        sound.play();
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
                        isRestartButSelected = true;
                        isMenuButSelected = false;
                        sound.play();
                    }
                break;            

                case sf::Keyboard::Down:
                    if (isRestartButSelected)
                    {
                        isRestartButSelected = false;
                        isMenuButSelected = true;
                        sound.play();
                    }
                    else if (isMenuButSelected)
                    {
                        isMenuButSelected = false;
                        isExitButSelected = true;
                        sound.play();
                    }
                break;

                case sf::Keyboard::S :
                    if (isRestartButSelected)
                    {
                        isRestartButSelected = false;
                        isMenuButPressed = true;
                        sound.play();
                    }
                    else if (isMenuButSelected)
                    {
                        isMenuButPressed = false;
                        isExitButSelected = true;
                        sound.play();
                    }
                break;

                case sf::Keyboard::Return:
                    isRestartButPressed = false;
                    isMenuButPressed = false;
                    isExitButPressed = false;

                    if (isRestartButSelected)
                    {
                        isRestartButPressed = true;
                    }
                    else if (isMenuButSelected)
                    {
                        isMenuButPressed = true;
                    }
                    else if (isExitButSelected)
                    {
                        isExitButPressed = true;
                    }
                break;

            case sf::Keyboard::Key::X:
                context->renderWin->close();
                context->quit = true;
                break;

            case sf::Keyboard::M:
                context->isMute = !(context->isMute);
                break;                

            default:
                break;
            }
        }
    }
}

void StateGameOverSFML::RestartGame()
{
    // Initialisation du joueur
    float x = context->map->GetSpawnsLayer()->GetPlayerSpawn().GetX();
    float y = context->map->GetSpawnsLayer()->GetPlayerSpawn().GetY();

    context->player = std::make_unique<Player>(x, y, "Player", 10, 10, 4, 10);

    context->map->GetCollisionLayer()->AddCollisionBoxEntity(
        context->player->GetID(), new Box(x, y, 26, 26));

    // Initialisation des ennemies
    int count = context->map->GetSpawnsLayer()->GetEnemySpawns().size();
    context->enemies.clear();

    for (int i = 0; i < count; i++)
    {
        x = context->map->GetSpawnsLayer()->GetEnemySpawns()[i].GetX();
        y = context->map->GetSpawnsLayer()->GetEnemySpawns()[i].GetY();

        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(x, y, "Enemy", 100, 3, 1, 100);
        context->enemies.push_back(enemy);
        
        context->map->GetCollisionLayer()->AddCollisionBoxEntity(
            enemy->GetID(), new Box(x, y, 26, 26));
    }

    // Initialisation des NPC
    std::string dialog;
    EntityDirection direction;
    count = context->map->GetSpawnsLayer()->GetNPCSpawns().size();
    for (int i = 0; i < count; i++){
        x = context->map->GetSpawnsLayer()->GetNPCSpawns()[i].GetX();
        y = context->map->GetSpawnsLayer()->GetNPCSpawns()[i].GetY();
        dialog = context->map->GetSpawnsLayer()->GetADialog(i);
        direction = context->map->GetSpawnsLayer()->GetADirection(i);
        // Ajout du npc au vector
        NPC * newNPC = new NPC(x, y, dialog);
        newNPC->SetDirection(direction);

        context->npc.push_back(newNPC);
            
        // Ajout de sa CollisionBox au CollisionLayer
        context->map->GetCollisionLayer()->AddCollisionBoxEntity(
            newNPC->GetID(), new Box(x, y, 32, 32));

    }
}

void StateGameOverSFML::Update()
{
    if (isRestartButSelected)
    {
        restartButton.setFillColor(sf::Color::White);
        restartButton.setOutlineColor(sf::Color::Black);
        menuButton.setFillColor(context->assetMan->GetMainTextColor());
        menuButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
    }
    else if (isMenuButSelected)
    {
        menuButton.setFillColor(sf::Color::White);
        menuButton.setOutlineColor(sf::Color::Black);
        restartButton.setFillColor(context->assetMan->GetMainTextColor());
        restartButton.setOutlineColor(sf::Color::Black);
        exitButton.setFillColor(context->assetMan->GetMainTextColor());
        exitButton.setOutlineColor(sf::Color::Black);
    }
        else if (isExitButSelected)
    {
        exitButton.setFillColor(sf::Color::White);
        exitButton.setOutlineColor(sf::Color::Black);
        restartButton.setFillColor(context->assetMan->GetMainTextColor());
        restartButton.setOutlineColor(sf::Color::Black);
        menuButton.setFillColor(context->assetMan->GetMainTextColor());
        menuButton.setOutlineColor(sf::Color::Black);
    }

    if (isRestartButPressed)
    {
        RestartGame();
        context->stateMan->Add(std::make_unique<StateGameSFML>(context), true);
    }
    else if (isMenuButPressed)
    {
        RestartGame();
        context->stateMan->Add(std::make_unique<StateMenuSFML>(context), true);
    }
    else if (isExitButPressed)
    {
        context->renderWin->close();
        context->quit = true;
    }

    if (context->isMute && music.getVolume() != 0 && sound.getVolume() != 0)
    {
        music.setVolume(0);
        sound.setVolume(0);
    }
    
    if (!context->isMute && music.getVolume() == 0 && sound.getVolume() != 0)
    {
        music.setVolume(70);
        sound.setVolume(100);
    }
}

void StateGameOverSFML::Display()
{
    context->renderWin->draw(bgSprite);
    context->renderWin->draw(logoSprite);
    context->renderWin->draw(gameOverText);
    context->renderWin->draw(restartButton);
    context->renderWin->draw(menuButton);
    context->renderWin->draw(exitButton);
    context->renderWin->display();
}

void StateGameOverSFML::Pause()
{
}

void StateGameOverSFML::Start()
{
}
