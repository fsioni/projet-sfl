#include "winTxt.h"
#include "gameTxt.h"


void txtLoop(Game & g) 
{
    WinTXT win(30, 30);
    system("setterm -cursor off");

    bool ok = true;
    int c;

    do
    {
        txtAff(win, g);
        //sleep(10);

        c = win.getCh();
		switch (c) {
			case 'x':
				ok = false;
                system("setterm -cursor on");
				break;
        default:
            g.KeyboardPressed(c);
            break;
		}
    } while (ok);
    
}

void txtAff(WinTXT & win, const Game & game) 
{
    const EntityWithHP& player = game.GetPlayerConst();
    const std::vector<CollisionBox> collisionBoxes = game.GetMapConst().GetCollisionLayer().GetCollisionBoxes();
    win.clear();

    //Affichage du joueur
    win.print(player.GetPos_x(), player.GetPos_y(), 'O');
    //Affichage des données du joueurs
    std::cout << endl << player.GetName() << " Informations : " << endl << "Position : (" << player.GetPos_x() << ", " << player.GetPos_y() << ")" << endl 
    << "HP : " << player.GetHP() << "/" << player.maxHealth << endl << "Speed : " << player.GetSpeed() << endl << "Is Alive " << player.livingStatus;

    //Affichage des collisions boxes
    for (unsigned int i=0; i < collisionBoxes.size(); i++){
        win.print(collisionBoxes[i].GetX(), collisionBoxes[i].GetY(), 'X');
    }
    

    win.draw();
}
