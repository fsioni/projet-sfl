#include "StateGameOverSFML.h"
#include "StateGameSFML.h"
#include <assert.h>

StateGameOverSFML::StateGameOverSFML(/* args */)
{
}

StateGameOverSFML::StateGameOverSFML(std::shared_ptr<Context> &cContext)
    : context(cContext)
{
}

StateGameOverSFML::~StateGameOverSFML()
{
}

void StateGameOverSFML::Init()
{
    assert(music.openFromFile("data/sounds/music/13gameover1V1NL.wav"));

    music.play();

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

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
    gameOverText.setPosition(winx / 2.0f, winy / 2.0f);

    restartText.setFont(context->assetMan->GetMainFont());
    restartText.setFillColor(context->assetMan->GetMainTextColor());
    restartText.setOutlineColor(sf::Color::Black);
    restartText.setOutlineThickness(2);
    restartText.setString("Press Space to restart");
    restartText.setCharacterSize(50);
    restartText.setOrigin(restartText.getLocalBounds().left +
                            restartText.getLocalBounds().width / 2.0f,
                            restartText.getLocalBounds().top +
                            restartText.getLocalBounds().height / 2.0f);
    restartText.setPosition(winx / 2.0f, winy / 2.0f + 150);
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
            case sf::Keyboard::Space:
                RestartGame();
                context->stateMan->Add(std::make_unique<StateGameSFML>(context),
                                        true);
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
    if (context->isMute && music.getVolume() != 0)
    {
        music.setVolume(0);
    }
    
    if (!context->isMute && music.getVolume() == 0)
    {
        music.setVolume(70);
    }
}

void StateGameOverSFML::Display()
{
    context->renderWin->draw(gameOverText);
    context->renderWin->draw(restartText);
    context->renderWin->display();
}

void StateGameOverSFML::Pause()
{
}

void StateGameOverSFML::Start()
{
}
