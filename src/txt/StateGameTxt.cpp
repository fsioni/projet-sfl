#include "StateGameTxt.h"



StateGameTxt::StateGameTxt(/* args */) 
{
    
}

StateGameTxt::StateGameTxt(std::shared_ptr<Context> &cContext) 
    : context(cContext)
{
    
}

StateGameTxt::~StateGameTxt() 
{

}

void StateGameTxt::Init() 
{
    context->player->SetSpeed(1);   

    system("setterm -cursor off");
}

void StateGameTxt::ProcessInput() 
{
    
}

void StateGameTxt::Update() 
{
    int c;

        c = win->getCh();
		switch (c) {
            case 'z' :
                MoveWithCollision(0, -1);
                context->player->SetDirection(Up);
                break;

            case 'q' :
                MoveWithCollision(-1, 0);
                context->player->SetDirection(Left);
                break;

            case 's' :
                MoveWithCollision(0, 1);
                context->player->SetDirection(Down);
                break;

            case 'd' :
                MoveWithCollision(1, 0);
                context->player->SetDirection(Right);
                break;
                                        
			case 'x':
                system("clear");
                system("setterm -cursor on");
				context->quit = true;
				break;
        default:
            break;
		}    
}

void StateGameTxt::Display() 
{
    win = make_unique<WinTXT>(50, 25);
    win->clear();


    //Affichage du joueur
    int pX = win->getDimx()/2; //center of the screen on x
    int pY = win->getDimy()/2; //center of the screen on y
    win->print(pX, pY, 'O');

    //Affichage des données du joueurs
    std::cout << endl << context->player->GetName() << " Informations : " << endl 
    << "Position : (" << context->player->GetPos_x() << ", " << context->player->GetPos_y() << ")" << endl 
    << "HP : " << context->player->GetHP() << "/" << context->player->GetMaxHealth() << endl;

    //Affichage des ennemies
        const std::vector<Enemy *> enemies = context->enemies;
        for (unsigned int i = 0; i < enemies.size(); i++)
    {
        win->print((pX - context->player->GetPos_x() + enemies[i]->GetPos_x()),
            (pY - context->player->GetPos_y() + enemies[i]->GetPos_y()), 'E');
    }
    

    //Affichage des collisions boxes
        const std::vector<CollisionBox> cb = context->map->GetCollisionLayer().GetCollisionBoxes();
    for (int i=0; i < (int)cb.size(); i++){
        int w = cb[i].GetWidth();
        int h = cb[i].GetHeight();
        for (int j = cb[i].GetX(); j <= cb[i].GetX() + w; j++)
        {
            for (int k = cb[i].GetY(); k <= cb[i].GetY() + h; k++)
            {
                win->print( (pX - context->player->GetPos_x() + j),
                    (pY - context->player->GetPos_y() + k), 'X');
            }
        }
    }


    win->draw();
}

void StateGameTxt::Pause() 
{
    
}

void StateGameTxt::Start() 
{
    
}

void StateGameTxt::MoveWithCollision(float vx, float vy) 
{
    if (vx == 0 && vy == 0)
    {
        return;
    }

    bool iscolliding = false;
    std::vector<CollisionBox> cb = context->map->GetCollisionLayer().GetCollisionBoxes();

    for (long unsigned int i = 0; i < cb.size(); i++)
    {
        int posX = context->player->GetPos_x() + 
                   vx*context->player->GetSpeed();
        int posY = context->player->GetPos_y() + 
                   vy*context->player->GetSpeed();

        //Detection collision axe X
        if (posX >= cb[i].GetX()
            && cb[i].GetX() + cb[i].GetWidth() >= posX){
            //Detection collision axe Y
            if(posY >= cb[i].GetY()
               && cb[i].GetY() + cb[i].GetHeight() >= posY){

                iscolliding = true;
            }   
        }
    }
    if (!iscolliding)
    {
        context->player->Move(vx, vy);
    }
}
