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

        // Chargement des charactères
        charTextures.loadFromFile("data/textures/characters/Male/Male 01-1.png");
        charSprite.setTexture(charTextures);

        // Chargement des ennemies
        enemyTexture.loadFromFile("data/textures/characters/Soldier/Soldier 01-1.png");
        enemySprite.setTexture(enemyTexture);

        // Chargement de l'ombre
        shadowTexture.loadFromFile("data/textures/characters/Shadow/Shadow 1.png");
        shadowSprite.setTexture(shadowTexture);
}

void StateGameSFML::ProcessInput()
{
    sf::Event Event;
    while(context->renderWin->pollEvent(Event)){
            
        switch (Event.type)
        {
        case sf::Event::Closed:
            context->renderWin->close();
            break;

        case sf::Event::KeyPressed:
            switch (Event.key.code)
            {
            case sf::Keyboard::Z:
                MoveWithCollision(0, -1);
                direction = 3;
                break;
            
            case sf::Keyboard::Q:
                MoveWithCollision(-1, 0);
                direction = 1;
                break;
            
            case sf::Keyboard::S:
                MoveWithCollision(0, 1);
                direction = 0;
                break;

            case sf::Keyboard::D:
                MoveWithCollision(1, 0);
                direction = 2;
                break;        

            case sf::Keyboard::P:
                context->isDebug = (!context->isDebug);
                break;
            
            case sf::Keyboard::X:
                context->renderWin->close();  
            
            case sf::Keyboard::Escape:
                context->renderWin->close();
            
            default:
                break;
            }
        
        default:
            break;
        }

        }
}

void StateGameSFML::Update()
{
    // Position du joueur
        playerX = context->player->GetPos_x();
        playerY = context->player->GetPos_y();

    // Info sur la tilemap
        w = context->map->GetTileset().GetTileWidth();
        h = context->map->GetTileset().GetTileHeight();
        nbMapLayer = context->map->GetMapLayers().size();
    
    // Gestion de camera qui suit le joueur
        substX = playerX-400;
        substY = playerY-400;

    // Gestion des bords de map
        if(substX<0) substX = 0;
        winWidth = (int)context->renderWin->getSize().x;
        winHeight =(int)context->renderWin->getSize().y;
        if(substX>winWidth) substX = winWidth;
        if(substY<0) substY = 0;
        if(substY>winHeight) substY = winHeight;

    if(clock.getElapsedTime().asSeconds() > 0.3){
            if(posX==64) posX=0;
            else posX +=32;
            
            clock.restart();
        }
}

void StateGameSFML::Display()
{
    context->renderWin->clear();

    // Affichage de la map
    for(int k=0; k<nbMapLayer; k++){
        MapLayer layer = context->map->GetMapLayers()[k];
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                data = layer.GetData(i, j);
                if(data!=0){
                    x = ((data-1) % 8)*w;
                    y = ((data-1) / 8)*h;

                    // Ne pas afficher les tiles non-visibles
                    int tileX = i*w - substX;
                    int tileY = j*h - substY;
                    if(tileX > -w && tileX < winWidth+w && 
                        tileY > -h && tileY < winHeight+h ){

                        tileSprite.setPosition(
                            i*w-substX, j*h-substY
                        );

                        tileSprite.setTextureRect(
                            sf::IntRect(x, y, w, h)
                        );

                        context->renderWin->draw(tileSprite);       
                    }

                        
                }
            }
        }
    }

    // Affichage de l'ombre
    shadowSprite.setPosition(playerX-substX, playerY-substY +2);
    shadowSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
    context->renderWin->draw(shadowSprite);
    

    // Affichage du joueur
    charSprite.setPosition(playerX-substX, playerY-substY);
    charSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
    context->renderWin->draw(charSprite);

    // Affichage des ennemies
    for(int i=0; i<(int)context->enemies.size(); i++){
        int enX = context->enemies[i].GetPos_x()-substX;
        int enY = context->enemies[i].GetPos_y()-substY;
        enemySprite.setPosition(enX, enY);
        enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        context->renderWin->draw(enemySprite);
    }

    

    if (context->isDebug) //Affichage DEBUG
    {
        //Affichage collisionBox du joueur
        int pOffset = context->player->getOffset();

        sf::RectangleShape pb(sf::Vector2f(context->player->GetWidth() - pOffset*2,
            context->player->GetHeight() -pOffset*2));
        pb.setPosition(context->player->GetPos_x() + pOffset -substX, 
            context->player->GetPos_y() + pOffset -substY);
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
        //Detection collision
        if (context->player->GetPos_x() + context->player->GetWidth() - context->player->getOffset() + (vx*context->player->GetSpeed()) >= cb[i].GetX()
        && cb[i].GetX() + cb[i].GetWidth() >= context->player->GetPos_x() + context->player->getOffset() + (vx*context->player->GetSpeed())
        && context->player->GetPos_y() + context->player->GetHeight() - context->player->getOffset() + (vy*context->player->GetSpeed()) >= cb[i].GetY()
        && cb[i].GetY() + cb[i].GetHeight() >= context->player->GetPos_y() + context->player->getOffset() + (vy*context->player->GetSpeed()))
            iscolliding = true;
    }
    if (!iscolliding)
    {
        context->player->Move(vx, vy);
    }
}
