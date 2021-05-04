#include "StateGameSFML.h"
#include "StatePauseSFML.h"
#include "StateGameOverSFML.h"
#include <string>
#include <assert.h>

StateGameSFML::StateGameSFML(/* args */)
{
}

StateGameSFML::StateGameSFML(std::shared_ptr<Context> &cContext)
    : context(cContext), isPaused(false)
{
}

StateGameSFML::~StateGameSFML()
{
}

void StateGameSFML::Init()
{
    // Chargement et lecture de la musique
    assert(music.openFromFile("data/sounds/music/01town2.wav"));
    assert(runningBuffer.loadFromFile("data/sounds/sfx/walking.wav"));
    assert(hitBuffer.loadFromFile("data/sounds/sfx/Slash_1.wav"));

    music.setVolume(70);
    music.setLoop(true);
    music.play();
    runningSound.setBuffer(runningBuffer);
    runningSound.setLoop(true);
    runningSound.stop();

    hitSound.setBuffer(hitBuffer);

    // Chargement de la tileMap
    tileTexture.loadFromFile(context->map->GetTileset()->GetTileMapPath());
    tileSprite.setTexture(tileTexture);

    // Chargement de la texture du joueur
    playerSprite.setTexture(context->assetMan->GetPlayerTexture());

    // Chargement de la texture des ennemies
    enemySprite.setTexture(context->assetMan->GetTextureEnemy()[0]);

    // Chargement de la texture de l'ombre
    shadowSprite.setTexture(context->assetMan->GetShadowTexture());

    // Initialisation UI
    assert(textFont.loadFromFile("./data/fonts/BebasNeue-Regular.ttf"));

    //int winx = context->renderWin->getSize().x;
    //int winy = context->renderWin->getSize().y;

    heartText.loadFromFile("./data/textures/UI/heart.png");
    heartSprite.setTexture(heartText);
    heartSprite.setScale(0.1f, 0.1f);
    heartSprite.setOrigin(heartSprite.getLocalBounds().left +
                              heartSprite.getLocalBounds().width / 2.0f,
                          heartSprite.getLocalBounds().top +
                              heartSprite.getLocalBounds().height / 2.0f);

    heartSprite.setPosition(20, 30);

    hpText.setFont(textFont);
    hpText.setString("0/0");
    hpText.setCharacterSize(30);

    hpText.setOrigin(hpText.getLocalBounds().left + hpText.getLocalBounds().width / 2.0f, hpText.getLocalBounds().top +
                                                                                              hpText.getLocalBounds().height / 2.0f);

    hpText.setPosition(60, 30);

    // Info sur la tilemap
    w = context->map->GetTileset()->GetTileWidth();
    h = context->map->GetTileset()->GetTileHeight();
    nbMapLayer = context->map->GetMapLayers().size();

    // Taille de la map
    mapWidth = context->map->GetMapLayers()[0].GetWidth();
    mapHeight = context->map->GetMapLayers()[0].GetHeight();

    fps = 0;

    lastHP = context->player->GetHP();

    // Init direction
    isGoingUp=false;
    isGoingDown=false;
    isGoingLeft=false;
    isGoingRight=false;
    // Init Attack
    isAttacking=false;

}

void StateGameSFML::ProcessInput()
{   
    sf::Event event;
    while (context->renderWin->pollEvent(event))
    {

        //Si la touche Z et S sont enfoncées
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) &&
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)))
        {
            isGoingUp = false;
            isGoingDown = false;
        }
        //Si la touche Z est enfoncée
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            isGoingUp = true;
            isGoingDown = false;
            context->player->SetDirection(Up);
        }
        //Si la touche S est enfoncée
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            isGoingUp = false;
            isGoingDown = true;
            context->player->SetDirection(Down);
        }
        //Si la touche ni Z ni S n'est enfoncée
        else
        {
            isGoingUp = false;
            isGoingDown = false;
        }

        //Si la touche Q et D sont enfoncées
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) && 
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
        {
            isGoingRight = false;
            isGoingLeft = false;
        }
        //Si la touche Q est enfoncée
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            isGoingRight = true;
            isGoingLeft = false;
            context->player->SetDirection(Left);
        }
        //Si la touche D est enfoncée
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            isGoingLeft = true;
            isGoingRight = false;
            context->player->SetDirection(Right);
        }
        //Si la touche ni Q ni D n'est enfoncée
        else
        {
            isGoingRight = false;
            isGoingLeft = false;
        }
        
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            isAttacking = true;
        }  

        switch (event.type)
        {
            //Si l'évènement actuel est celui de fermeture: quitter le jeu
        case sf::Event::Closed:
            context->renderWin->close();
            context->quit = true;
            break;

        case sf::Event::KeyPressed:

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
            {
                context->isDebug = (!context->isDebug);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
            {
                context->renderWin->close();
                context->quit = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
            {
                context->isMute = (!context->isMute);
            }
            

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                context->stateMan->Add(std::make_unique<StatePauseSFML>(context));
            }

            break;

        case sf::Event::Resized:
            winWidth = event.size.width;
            winHeight = event.size.height;
            context->renderWin->setView(sf::View(
                sf::FloatRect(0, 0, event.size.width, event.size.height)));
            break;

        default:
            break;
        }
    }
}

void StateGameSFML::Update()
{
    if (!isPaused)
    {
        if (context->player->GetLivingStatus() == false)
        {
            context->stateMan->Add(std::make_unique<StateGameOverSFML>(context), true);
        }
         

        deltaTime = deltaClock.restart().asMilliseconds();

        if (fpsClock.getElapsedTime().asSeconds() > 0.5)
        {
            fps = 1000 / deltaTime;
            fpsClock.restart();
        }

        // Position du joueur
        playerX = context->player->GetPos_x();
        playerY = context->player->GetPos_y();
        
        // Gestion de camera qui suit le joueur
        substX = playerX - winWidth / 2;
        substY = playerY - winHeight / 2;

        // Taille de la fenetre
        winWidth = (int)context->renderWin->getSize().x;
        winHeight = (int)context->renderWin->getSize().y;

        // Gestion des bords de map
        if (substX < 0)
            substX = 0;
        if (substX > mapWidth * w - winWidth)
            substX = mapWidth * w - winWidth;
        if (substY < 0)
            substY = 0;
        if (substY > mapHeight * h - winHeight)
            substY = mapHeight * h - winHeight;
       
        UpdatePlayer();
        UpdateEnemies();
        
    
        // Mise à jour texte UI
        std::string hp = std::to_string(context->player->GetHP());
        std::string maxHp = std::to_string(context->player->GetMaxHP());
        hpText.setString("HP : " + hp + "/" + maxHp);
    }
    else
    {
        deltaTime = 0;
        deltaClock.restart();
        fpsClock.restart();
    }

    //  Mise à jour du son
        if (!isWalking && 
        runningSound.getStatus() == sf::SoundSource::Status::Playing)
    {
        runningSound.stop();
    }
    
        if (isWalking && 
        runningSound.getStatus() == sf::SoundSource::Status::Stopped)
    {
        runningSound.play();
    }

    if (context->isMute && (runningSound.getVolume() != 0 || music.getVolume() != 0))
    {
        runningSound.setVolume(0);
        music.setVolume(0);
    }
    
    if (!context->isMute && (runningSound.getVolume() == 0 || music.getVolume() == 0))
    {
        runningSound.setVolume(100);
        music.setVolume(70);
    }
}

void StateGameSFML::UpdatePlayer()
{
    context->player->SetIsMovingFalse();

    CollisionLayer * colLayer = context->map->GetCollisionLayer();
    
    // Gestion mouvement joueur
    if (isGoingUp && isGoingLeft)
    {
        context->player->MoveWithCollision(0.5f, -0.5f, colLayer, deltaTime);
    }
    else if (isGoingUp && isGoingRight)
    {
        context->player->MoveWithCollision(-0.5f, -0.5f, colLayer, deltaTime);
    }else if (isGoingUp)
    {
        context->player->MoveWithCollision(0, -1, colLayer, deltaTime);
    }

    if (isGoingDown && isGoingLeft)
    {
        context->player->MoveWithCollision(0.5f, 0.5f, colLayer, deltaTime);
    }else if (isGoingDown && isGoingRight)
    {
        context->player->MoveWithCollision(-0.5f, 0.5f, colLayer, deltaTime);
    }else if (isGoingDown)
    {
        context->player->MoveWithCollision(0, 1, colLayer, deltaTime);
    }

    if (isGoingRight && !isGoingUp && !isGoingDown)
    {
        context->player->MoveWithCollision(-1, 0, colLayer, deltaTime);
    }

    if (isGoingLeft && !isGoingUp && !isGoingDown)
    {
        context->player->MoveWithCollision(1, 0, colLayer, deltaTime);
    }

    if(isAttacking){
        int count = context->enemies.size();
        for(int i=0; i<count; i++){
            context->player->Attack(context->enemies[i], context->map->GetCollisionLayer());
        }
        isAttacking = false;
    }

    if (!isGoingLeft && !isGoingRight && !isGoingUp && !isGoingDown)
    {
        isWalking = false;
    }else
    {
        isWalking = true;
    }

    int playerID= context->player->GetID();
    int playerX = context->player->GetPos_x();
    int playerY = context->player->GetPos_y();
    

    CollisionBox * cbPlayer = 
        context->map->GetCollisionLayer()->GetCollisionBoxesEntity()[playerID];
    

    cbPlayer->SetPosition(playerX, playerY);
    
    
    // Gestion animation joueur
    if (spriteClock.getElapsedTime().asSeconds() > 0.3)
    {
        if (posX == 64)
            posX = 0;
        else
            posX += 32;

        spriteClock.restart();
    }

    if (lastHP != context->player->GetHP())
    {
        playerSprite.setColor(sf::Color::Red);
        hitSound.play();
        hitClock.restart();
    }

    if (hitClock.getElapsedTime().asSeconds() > 0.2)
    {
        playerSprite.setColor(sf::Color::White);
    }

    lastHP = context->player->GetHP();
}

void StateGameSFML::UpdateEnemies()
{
    int count = context->enemies.size();

    for (int i = 0; i < count; i++)
    {
        // Si enemy est en vie on fait tous les Updates
        if (context->enemies[i]->GetLivingStatus())
        {
            context->enemies[i]->SetIsMovingFalse();
            context->enemies[i]->UpdateStateMachine(context->player,
                context->map->GetCollisionLayer(), deltaTime);
            
            
            float posX = context->enemies[i]->GetPos_x();
            float posY = context->enemies[i]->GetPos_y();
            int enemyID = context->enemies[i]->GetID();

            CollisionBox * cbEnemy = 
                context->map->GetCollisionLayer()->GetCollisionBoxesEntity()[enemyID];

            cbEnemy->SetPosition(posX, posY);
        } 
        else{
            int enemyID = context->enemies[i]->GetID();
            context->map->GetCollisionLayer()->DeleteACollisionBoxEntity(enemyID);
            context->enemies.erase(context->enemies.begin()+i);
            count--;
        }
    }

    // Mise à jour texte UI
    std::string hp = std::to_string(context->player->GetHP());
    std::string maxHp = std::to_string(context->player->GetMaxHP());
    hpText.setString("HP :" + hp + "/" + maxHp);
}

void StateGameSFML::Display()
{
    context->renderWin->clear();

    DisplayMap();
    DisplayPlayer();
    DisplayEnemies();

    if (context->isDebug) //Affichage DEBUG
    {
        DisplayDebug();
    }

    ///////////// UI ///////////////
    context->renderWin->draw(hpText);
    context->renderWin->draw(heartSprite);

    context->renderWin->display();
}

void StateGameSFML::DisplayMap()
{
    for (int k = 0; k < nbMapLayer; k++)
    {
        MapLayer layer = context->map->GetMapLayers()[k];
        for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                data = layer.GetData(i, j);
                if (data != 0)
                {
                    x = ((data - 1) % 8) * w;
                    y = ((data - 1) / 8) * h;

                    // Ne pas afficher les tiles non-visibles
                    int tileX = i * w - substX;
                    int tileY = j * h - substY;

                    if (tileX > -w && tileX < winWidth + w &&
                        tileY > -h && tileY < winHeight + h)
                    {

                        tileSprite.setPosition(tileX, tileY);

                        tileSprite.setTextureRect(sf::IntRect(x, y, w, h));

                        context->renderWin->draw(tileSprite);
                    }
                }
            }
        }
    }
}

void StateGameSFML::DisplayPlayer()
{
    // -h/2 et -w/2 pour recentrer l'origine des entités
    int direction = context->player->GetDirection();
    int pX = playerX - substX - w / 2;
    int pY = playerY - substY - h / 2;

    // Affichage de l'ombre
    shadowSprite.setPosition(pX, pY);
    shadowSprite.setTextureRect(sf::IntRect(posX, direction * 32, 32, 32));
    context->renderWin->draw(shadowSprite);

    // Affichage du joueur
    playerSprite.setPosition(pX, pY);
    if (context->player->GetIsMoving())
        playerSprite.setTextureRect(sf::IntRect(posX, direction * 32, 32, 32));
    else
        playerSprite.setTextureRect(sf::IntRect(0, direction * 32, 32, 32));
    context->renderWin->draw(playerSprite);
}

void StateGameSFML::DisplayEnemies()
{
    for (int i = 0; i < (int)context->enemies.size(); i++)
    {

        if (context->enemies[i]->GetLivingStatus())
        {
            int direction = context->enemies[i]->GetDirection();
            int enX = context->enemies[i]->GetPos_x() - substX - w / 2;
            int enY = context->enemies[i]->GetPos_y() - substY - h / 2;

            // Affichage de l'ombre
            shadowSprite.setPosition(enX, enY);
            shadowSprite.setTextureRect(sf::IntRect(posX, direction * 32, 32,
                                                    32));
            context->renderWin->draw(shadowSprite);

            // Affichage des ennemies
            enemySprite.setPosition(enX, enY);
            if (context->enemies[i]->GetIsMoving())
                enemySprite.setTextureRect(sf::IntRect(posX, direction * 32,
                                                       32, 32));
            else
                enemySprite.setTextureRect(sf::IntRect(0, direction * 32, 32,
                                                       32));

            context->renderWin->draw(enemySprite);
        }
    }
}

void StateGameSFML::DisplayCollisionBox(CollisionBox * cb, const sf::Color & color, int id){
    sf::RectangleShape rectColBox(
        sf::Vector2f(cb->GetWidth(), cb->GetHeight())
    );
    int x = cb->GetX() - substX - 16;
    int y = cb->GetY() - substY - 16;

    rectColBox.setPosition(x, y);
    rectColBox.setFillColor(color);
    context->renderWin->draw(rectColBox);

  
    // Affichage position 
    std::string position = "("+ std::to_string(cb->GetX()) + ", " 
                    + std::to_string(cb->GetY()) + " )";
    
    
    sf::Text pos_text(position, textFont);   

    pos_text.setPosition(cb->GetX() -substX -25, cb->GetY() -substY+10);
    pos_text.setCharacterSize(15);
       
    context->renderWin->draw(pos_text);

    // Affichage ID
    std::string ID = "ID = " + std::to_string(id);
    sf::Text id_text(ID, textFont);
    id_text.setPosition(cb->GetX() -substX -17, cb->GetY() -substY-10);

    id_text.setCharacterSize(15);
    context->renderWin->draw(id_text);
}

void StateGameSFML::DisplayDebug(){
    //Affichage du debug du joueur

    int playerID = context->player->GetID();
    CollisionBox * cbPlayer = 
        context->map->GetCollisionLayer()->GetCollisionBoxesEntity()[playerID];

    //Affichage de la collision box player
    DisplayCollisionBox(cbPlayer, sf::Color(170, 30, 155, 200), playerID);
    
    // CollisionBoxes enemy
    for (long unsigned int i=0; i < context->enemies.size(); i++)
    {
        int enemyID = context->enemies[i]->GetID();

        CollisionBox * enemyBoxe = 
            context->map->GetCollisionLayer()->GetCollisionBoxesEntity()[enemyID]; 
        DisplayCollisionBox(enemyBoxe, sf::Color(170, 30, 155, 200), enemyID);
    }    


    // Affichage des collision boxes de la map
    std::vector<CollisionBox> collisionBoxes =
        context->map->GetCollisionLayer()->GetCollisionBoxes();

    for (long unsigned int i=0; i < collisionBoxes.size(); i++)
    {
        sf::RectangleShape cb(sf::Vector2f(collisionBoxes[i].GetWidth(),
                                           collisionBoxes[i].GetHeight()));
        cb.setPosition(collisionBoxes[i].GetX() - substX,
                       collisionBoxes[i].GetY() - substY);
        cb.setFillColor(sf::Color(0, 190, 255, 215));
        context->renderWin->draw(cb);
    }

   
    //Affichage des FPS
    sf::Text fps_text(std::to_string(fps), textFont);

    fps_text.setPosition(winWidth - 35, 10);
    fps_text.setCharacterSize(20);
    fps_text.setFillColor(sf::Color::Blue);
 
    context->renderWin->draw(fps_text);  
}

void StateGameSFML::Pause()
{
    isPaused = true;
}

void StateGameSFML::Start()
{
    isPaused = false;
    deltaTime = 0;
    deltaClock.restart();
    fpsClock.restart();
}