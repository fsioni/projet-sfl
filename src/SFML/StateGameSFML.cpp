#include "StateGameSFML.h"
#include <string>
#include <assert.h>

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
                            heartSprite.getLocalBounds().width/2.0f, 
                            heartSprite.getLocalBounds().top +
                            heartSprite.getLocalBounds().height/2.0f);

    heartSprite.setPosition(20, 30);


    hpText.setFont(textFont);
    hpText.setString("0/0");
    hpText.setCharacterSize(30);

    hpText.setOrigin(hpText.getLocalBounds().left+hpText.getLocalBounds().width
                    / 2.0f, hpText.getLocalBounds().top + 
                    hpText.getLocalBounds().height/2.0f);

    hpText.setPosition(60, 30);

    // Info sur la tilemap
    w = context->map->GetTileset()->GetTileWidth();
    h = context->map->GetTileset()->GetTileHeight();
    nbMapLayer = context->map->GetMapLayers().size();

    // Taille de la map
    mapWidth = context->map->GetMapLayers()[0].GetWidth();
    mapHeight = context->map->GetMapLayers()[0].GetHeight();
    
}

void StateGameSFML::ProcessInput()
{
    sf::Event event;
    while(context->renderWin->pollEvent(event)){

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

        switch (event.type)
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

    // Gestion de camera qui suit le joueur
    substX = playerX - winWidth/2;
    substY = playerY - winHeight/2;

    // Taille de la fenetre
    winWidth = (int)context->renderWin->getSize().x;
    winHeight =(int)context->renderWin->getSize().y;

    // Gestion des bords de map
    if(substX < 0) substX = 0;
    if(substX > mapWidth*w - winWidth) substX = mapWidth*w - winWidth;
    if(substY < 0) substY = 0;
    if(substY > mapHeight*h - winHeight) substY = mapHeight*h - winHeight;

    UpdatePlayer();
    UpdateEnemies();

    
    // Mise à jour texte UI
    std::string hp = std::to_string(context->player->GetHP());
    std::string maxHp = std::to_string(context->player->GetMaxHealth());
    hpText.setString("HP :" + hp + "/" + maxHp);
}

void StateGameSFML::UpdatePlayer(){
    // Gestion mouvement joueur
    if (isGoingUp && isGoingLeft)
    {
        MovePlayerWithCollision(0.5f, -0.5f);
    }else if (isGoingUp && isGoingRight)
    {
        MovePlayerWithCollision(-0.5f, -0.5f);
    }else if (isGoingUp)
    {
        MovePlayerWithCollision(0, -1);
    }

    if (isGoingDown && isGoingLeft)
    {
        MovePlayerWithCollision(0.5f, 0.5f);
    }else if (isGoingDown && isGoingRight)
    {
        MovePlayerWithCollision(-0.5f, 0.5f);
    }else if (isGoingDown)
    {
        MovePlayerWithCollision(0, 1);
    }

    if (isGoingRight && !isGoingUp && !isGoingDown)
    {
        MovePlayerWithCollision(-1,0);
    }
    
    if (isGoingLeft && !isGoingUp && !isGoingDown)
    {
        MovePlayerWithCollision(1,0);
    }


    std::shared_ptr<CollisionBox> cbPlayer = context->player->GetCollisionBox();
    cbPlayer->SetX(context->player->GetPos_x());
    cbPlayer->SetY(context->player->GetPos_y());
    
    // Gestion animation joueur
    if(spriteClock.getElapsedTime().asSeconds() > 0.3){
        if(posX==64) posX=0;
        else posX +=32;
            
        spriteClock.restart();
    }
}

void StateGameSFML::UpdateEnemies(){
    int count = context->enemies.size();
    
    for(int i=0; i<count; i++){
        context->enemies[i]->UpdateStateMachine(context->player,
            context->map->GetCollisionLayer(), deltaTime);
        
        context->enemies[i]->DecrementNbUpdateChangeDir();
        float posX = context->enemies[i]->GetPos_x();
        float posY = context->enemies[i]->GetPos_y();
       
        context->map->GetCollisionLayer()->GetCollisionBoxesEnemy()[i]->
        SetPosition(posX-16, posY-16);
        context->enemies[i]->GetCollisionBox()->SetPosition(posX-16, posY-16);
        
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
    int pX = playerX-substX - w/2;
    int pY = playerY-substY -h/2;
    shadowSprite.setPosition(pX, pY);
    shadowSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
    context->renderWin->draw(shadowSprite);
    

    // Affichage du joueur
    playerSprite.setPosition(pX, pY);
    playerSprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
    context->renderWin->draw(playerSprite);

    // Affichage des ennemies
    for(int i=0; i<(int)context->enemies.size(); i++){
        direction = context->enemies[i]->GetDirection();
        int enX = context->enemies[i]->GetPos_x() - substX - w/2;
        int enY = context->enemies[i]->GetPos_y() - substY - h/2;
        enemySprite.setPosition(enX, enY);
        enemySprite.setTextureRect(sf::IntRect(posX, direction*32, 32, 32));
        context->renderWin->draw(enemySprite);
    }

    

    if (context->isDebug) //Affichage DEBUG
    {
        DisplayDebug();            
    }

    ///////////// UI ///////////////
    context->renderWin->draw(hpText);
    context->renderWin->draw(heartSprite);





    context->renderWin->display();

}

void StateGameSFML::DisplayDebug(){
    //Affichage du debug du joueur
    int pOffset = context->player->GetOffset();

    std::shared_ptr<CollisionBox> cbPlayer = context->player->GetCollisionBox();

    //Affichage de la collision box
    sf::RectangleShape pb(sf::Vector2f(cbPlayer->GetWidth() - pOffset*2,
        cbPlayer->GetHeight() -pOffset*2));
    pb.setPosition(cbPlayer->GetX() + pOffset -substX -w/2, 
        cbPlayer->GetY() + pOffset -substY -h/2);
    pb.setFillColor(sf::Color(170, 30, 155, 200));

    //Affichage des coordonnées
    sf::String txt= "("+  to_string(context->player->GetPos_x()) + ", " + to_string(context->player->GetPos_y())+ ")";
    sf::Text pos_text(txt, textFont);   

    pos_text.setPosition(context->player->GetPos_x() -substX, context->player->GetPos_y() + 10 -substY);
    pos_text.setCharacterSize(15);

    context->renderWin->draw(pb);   
    context->renderWin->draw(pos_text);    

    // Affichage des collision boxes de la map
    std::vector<CollisionBox> collisionBoxes = 
        context->map->GetCollisionLayer()->GetCollisionBoxes();

    

    for (long unsigned int i=0; i < collisionBoxes.size(); i++)
    {
        sf::RectangleShape cb(sf::Vector2f(collisionBoxes[i].GetWidth(), collisionBoxes[i].GetHeight()));
        cb.setPosition(collisionBoxes[i].GetX() -substX, collisionBoxes[i].GetY()-substY);
        cb.setFillColor(sf::Color(0, 190, 255, 200));
        context->renderWin->draw(cb);                
    }   

    // Affichage du debug des entités
    std::vector<std::shared_ptr<CollisionBox> > enemyBoxes = 
        context->map->GetCollisionLayer()->GetCollisionBoxesEnemy();

    for (long unsigned int i=0; i < enemyBoxes.size(); i++)
    {
        //Affichage des collisions boxes
        int x = enemyBoxes[i]->GetX() -substX;
        int y = enemyBoxes[i]->GetY()-substY;
        sf::RectangleShape cb(sf::Vector2f(enemyBoxes[i]->GetWidth(), enemyBoxes[i]->GetHeight()));
        cb.setPosition(x, y);
        cb.setFillColor(sf::Color(0, 190, 55, 200));

        //Affichage de l'id et des coordonnées
        sf::String txt= "id: "+ to_string(enemyBoxes[i]->GetId());

        sf::Text id_text(txt, textFont);
        txt = "("+  to_string(enemyBoxes[i]->GetX()) + ", " + to_string(enemyBoxes[i]->GetY())+ ")";
        sf::Text pos_text(txt, textFont);
        id_text.setPosition(x, y);
        id_text.setCharacterSize(15);
        

        pos_text.setPosition(x, y+20);
        pos_text.setCharacterSize(15);


        context->renderWin->draw(cb); 
        context->renderWin->draw(id_text);    
        context->renderWin->draw(pos_text);      
    }
}

void StateGameSFML::Pause()
{
    
}

void StateGameSFML::Start()
{
    
}

void StateGameSFML::MovePlayerWithCollision(float vx, float vy) 
{
    if (vx == 0 && vy == 0)
    {
        return;
    }
    bool iscolliding = false;
    std::vector<CollisionBox> cb = 
        context->map->GetCollisionLayer()->GetCollisionBoxes();
    
    std::shared_ptr<CollisionBox> cbPlayer = context->player->GetCollisionBox();

    // -w/2 et -h/2 pour centrer l'origine 
    int posX = cbPlayer->GetX() + 
               vx*context->player->GetSpeed() - w/2;
    int posY = cbPlayer->GetY() + 
               vy*context->player->GetSpeed() - h/2;


    for (long unsigned int i = 0; i < cb.size(); i++)
    {
       int offset = context->player->GetOffset();
        //Detection collision axe X
        if (posX + cbPlayer->GetWidth() - offset >= cb[i].GetX()
            && cb[i].GetX() + cb[i].GetWidth() >= posX + offset){
            //Detection collision axe Y
            if(posY + cbPlayer->GetHeight() - offset >= cb[i].GetY()
               && cb[i].GetY() + cb[i].GetHeight() >= posY + offset){

                iscolliding = true;
            }   
        }
    }
    std::vector<std::shared_ptr<CollisionBox> > cbEnemy = 
        context->map->GetCollisionLayer()->GetCollisionBoxesEnemy();
    
    for (long unsigned int i = 0; i < cbEnemy.size(); i++)
    {
        int offset = context->player->GetOffset();

        //Detection collision axe X
        if (posX + cbPlayer->GetWidth() - offset >= cbEnemy[i]->GetX()
            && cbEnemy[i]->GetX() + cbEnemy[i]->GetWidth() >= posX + offset){
            //Detection collision axe Y
            if(posY + cbPlayer->GetHeight() - offset >= cbEnemy[i]->GetY()
               && cbEnemy[i]->GetY() + cbEnemy[i]->GetHeight() >= posY + offset){
                iscolliding = true;
            }   
        }
    }

    if (!iscolliding)
    {
        context->player->Move((vx*deltaTime)/30, (vy*deltaTime)/30);
    }
}
