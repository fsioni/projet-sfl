#include "StateGameSFML.h"


StateGameSFML::StateGameSFML(/* args */)
{
}

StateGameSFML::StateGameSFML(std::shared_ptr<Context> &cContext)
    : context(cContext)
{
}

StateGameSFML::~StateGameSFML()
{
}

void StateGameSFML::Init()
{
    // Chargement de la tileMap
    tileTexture.loadFromFile(context->map->GetTileset().GetTileMapPath());
    tileSprite.setTexture(tileTexture);

    // Chargement de la texture du joueur
    playerSprite.setTexture(context->assetMan->GetPlayerTexture());

    // Chargement de la texture des ennemies
    enemySprite.setTexture(context->assetMan->GetTextureEnemy()[0]);

    // Chargement de la texture de l'ombre
    shadowSprite.setTexture(context->assetMan->GetShadowTexture());
}

void StateGameSFML::ProcessInput()
{
    sf::Event Event;
    while(context->renderWin->pollEvent(Event)){

            //Si la touche Z et S sont enfoncées
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                isGoingUp = false;
                isGoingDown = false;
            }
            //Si la touche Z est enfoncée
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) 
            {
                isGoingUp = true;
                isGoingDown = false;
                context->player->SetDirection(Up);
            }
            //Si la touche S est enfoncée
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                isGoingRight = false;
                isGoingLeft = false;
            }
            //Si la touche Q est enfoncée
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            {
                isGoingRight = true;
                isGoingLeft = false;
                context->player->SetDirection(Left);
            }
            //Si la touche D est enfoncée
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
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

        switch (Event.type)
        {
            //Si l'évènement actuel est celui de fermeture: quitter le jeu
        case sf::Event::Closed:
            context->renderWin->close();
            context->quit = true;
            break;

        case sf::Event::KeyPressed:

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
                context->isDebug = (!context->isDebug);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X) 
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                context->renderWin->close();
                context->quit = true;
            }
            break;
        
        default:
            break;
        }

        }
}

void StateGameSFML::Update()
{
    deltaTime = deltaClock.restart().asMilliseconds();

    // Position du joueur
    playerX = context->player->GetPos_x();
    playerY = context->player->GetPos_y();

    // Info sur la tilemap
    w = context->map->GetTileset().GetTileWidth();
    h = context->map->GetTileset().GetTileHeight();
    nbMapLayer = context->map->GetMapLayers().size();

    // Taille de la map
    mapWidth = context->map->GetMapLayers()[0].GetWidth();
    mapHeight = context->map->GetMapLayers()[0].GetHeight();
    
    // Gestion de camera qui suit le joueur
    substX = playerX - winWidth/2;
    substY = playerY - winHeight/2;

    // Taille de la fenetre
    winWidth = (int)context->renderWin->getSize().x;
    winHeight =(int)context->renderWin->getSize().y;

    // Gestion mouvement joueur
    if (isGoingUp && isGoingLeft)
    {
        MoveWithCollision(0.5f, -0.5f);
    }else if (isGoingUp && isGoingRight)
    {
        MoveWithCollision(-0.5f, -0.5f);
    }else if (isGoingUp)
    {
        MoveWithCollision(0, -1);
    }

    if (isGoingDown && isGoingLeft)
    {
        MoveWithCollision(0.5f, 0.5f);
    }else if (isGoingDown && isGoingRight)
    {
        MoveWithCollision(-0.5f, 0.5f);
    }else if (isGoingDown)
    {
        MoveWithCollision(0, 1);
    }

    if (isGoingRight && !isGoingUp && !isGoingDown)
    {
        MoveWithCollision(-1,0);
    }
    
    if (isGoingLeft && !isGoingUp && !isGoingDown)
    {
        MoveWithCollision(1,0);
    }
    

    // Gestion des bords de map
    if(substX < 0) substX = 0;
    if(substX > mapWidth*w - winWidth) substX = mapWidth*w - winWidth;
    if(substY < 0) substY = 0;
    if(substY > mapHeight*h - winHeight) substY = mapHeight*h - winHeight;

    // Gestion animation joueur
    if(spriteClock.getElapsedTime().asSeconds() > 0.3){
        if(posX==64) posX=0;
        else posX +=32;
            
        spriteClock.restart();
    }
}

void StateGameSFML::Display()
{
    context->renderWin->clear();

    // Affichage de la map
    for(int k=0; k<nbMapLayer; k++){
        MapLayer layer = context->map->GetMapLayers()[k];
        for(int i=0; i<mapWidth; i++){
            for(int j=0; j<mapHeight; j++){
                data = layer.GetData(i, j);
                if(data!=0){
                    x = ((data-1) % 8)*w;
                    y = ((data-1) / 8)*h;
                    
                    // Ne pas afficher les tiles non-visibles
                    int tileX = i*w - substX;
                    int tileY = j*h - substY;
                    
                    if(tileX > -w && tileX < winWidth+w && 
                        tileY > -h && tileY < winHeight+h ){
                        
                       

                        tileSprite.setPosition(tileX, tileY);

                        tileSprite.setTextureRect(sf::IntRect(x, y, w, h));
                      
                        context->renderWin->draw(tileSprite);       
                    }

                        
                }
            }
        }
    }

    // -h/2 et -w/2 pour recentrer l'origine des entités
    // Affichage de l'ombre
    int direction = context->player->GetDirection();
    shadowSprite.setPosition(playerX-substX - w/2, playerY-substY -h/2 +2);
    shadowSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
    context->renderWin->draw(shadowSprite);
    

    // Affichage du joueur
    playerSprite.setPosition(playerX-substX -w/2, playerY-substY -h/2);
    playerSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
    context->renderWin->draw(playerSprite);

    // Affichage des ennemies
    for(int i=0; i<(int)context->enemies.size(); i++){
        direction = context->enemies[i].GetDirection();
        int enX = context->enemies[i].GetPos_x()-substX;
        int enY = context->enemies[i].GetPos_y()-substY;
        enemySprite.setPosition(enX -w/2, enY -h/2);
        enemySprite.setTextureRect(sf::IntRect(posX, 0, 32, 32));
        context->renderWin->draw(enemySprite);
    }

    

    if (context->isDebug) //Affichage DEBUG
    {
        //Affichage collisionBox du joueur
        int pOffset = context->player->getOffset();

        sf::RectangleShape pb(sf::Vector2f(context->player->GetWidth() - pOffset*2,
            context->player->GetHeight() -pOffset*2));
        pb.setPosition(context->player->GetPos_x() + pOffset -substX -w/2, 
            context->player->GetPos_y() + pOffset -substY -h/2);
        pb.setFillColor(sf::Color(0, 130, 255, 200));
        context->renderWin->draw(pb);

        // Affichage des collision boxes
        const std::vector<CollisionBox> collisionBoxes = 
            context->map->GetCollisionLayer().GetCollisionBoxes();

        for (long unsigned int i=0; i < collisionBoxes.size(); i++)
        {
            sf::RectangleShape cb(sf::Vector2f(collisionBoxes[i].GetWidth(), collisionBoxes[i].GetHeight()));
            cb.setPosition(collisionBoxes[i].GetX() -substX, collisionBoxes[i].GetY()-substY);
            cb.setFillColor(sf::Color(0, 190, 255, 200));
            context->renderWin->draw(cb);                
        }            
    }


    context->renderWin->display();

}

void StateGameSFML::Pause()
{
    
}

void StateGameSFML::Start()
{
    
}



void StateGameSFML::MoveWithCollision(float vx, float vy) 
{
    if (vx == 0 && vy == 0)
    {
        return;
    }
    bool iscolliding = false;
    std::vector<CollisionBox> cb = context->map->GetCollisionLayer().GetCollisionBoxes();
    for (long unsigned int i = 0; i < cb.size(); i++)
    {

        // -w/2 et -h/2 pour centrer l'origine 
        int posX = context->player->GetPos_x() + 
                   vx*context->player->GetSpeed() - w/2;
        int posY = context->player->GetPos_y() + 
                   vy*context->player->GetSpeed() - h/2;

        int offset = context->player->getOffset();
        //Detection collision axe X
        if (posX + context->player->GetWidth() - offset >= cb[i].GetX()
            && cb[i].GetX() + cb[i].GetWidth() >= posX + offset){
            //Detection collision axe Y
            if(posY + context->player->GetHeight() - offset >= cb[i].GetY()
               && cb[i].GetY() + cb[i].GetHeight() >= posY + offset){

                iscolliding = true;
            }   
        }
    }
    if (!iscolliding)
    {
        context->player->Move((vx*deltaTime)/30, (vy*deltaTime)/30);
    }
}
