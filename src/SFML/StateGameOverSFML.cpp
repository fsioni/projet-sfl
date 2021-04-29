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
    assert(textFont.loadFromFile("./data/fonts/BebasNeue-Regular.ttf"));
    assert(music.openFromFile("data/sounds/music/13gameover1V1NL.wav"));

    music.play();

    int winx = context->renderWin->getSize().x;
    int winy = context->renderWin->getSize().y;

    gameOverText.setFont(textFont);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(50);
    gameOverText.setOrigin(gameOverText.getLocalBounds().left + 
                            gameOverText.getLocalBounds().width / 2.0f,
                            gameOverText.getLocalBounds().top + 
                            gameOverText.getLocalBounds().height / 2.0f);
    gameOverText.setPosition(winx / 2.0f, winy / 2.0f);

    restartText.setFont(textFont);
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

            default:
                break;
            }
        }
    }
}

void StateGameOverSFML::RestartGame()
{
    //Initialisation du joueur
    context->player = std::make_unique<Player>(context->map->GetSpawnsLayer()->
                        getPlayerSpawn().GetX(), context->map->GetSpawnsLayer()
                        ->getPlayerSpawn().GetY(), "Player", 10, 10, 4, 10);

    // Initialisation des ennemies
    int count = context->map->GetSpawnsLayer()->getEnemySpawns().size();
    context->enemies.clear();

    for (int i = 0; i < count; i++)
    {
        int x = context->map->GetSpawnsLayer()->getEnemySpawns()[i].GetX();
        int y = context->map->GetSpawnsLayer()->getEnemySpawns()[i].GetY();

        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(x, y, "Enemy", 100, 3, 1, 100);
        context->enemies.push_back(enemy);
        
        context->map->GetCollisionLayer()->AddCollisionBoxEntity(
            enemy->GetID(), new CollisionBox(x, y, 26, 26));
    }
}

void StateGameOverSFML::Update()
{
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
