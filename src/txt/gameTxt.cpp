#include "winTxt.h"
#include "gameTxt.h"


void txtLoop(Game & g) 
{
    WinTXT win(20, 20);
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
    win.clear();

    //Affichage du joueur
    win.print(player.GetPos_x(), player.GetPos_y(), 'O');
    std::cout << endl << "'" << player.GetPos_x() << ", " << player.GetPos_y() << "'" << endl << "Player HP : " << player.GetHP() << endl;

    win.draw();
}
