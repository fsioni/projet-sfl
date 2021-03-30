#include <iostream>
#include <string>
#include "txt/gameTxt.h"
#include "SFML/DisplayGame.h"


int main(int argc, char* argv[]){

    if (argc == 1 || argc>2) //////CHECK DU NOMBRE D'ARGUMENTS
    {
        cerr << "You need one argument : 0 for SFML, 1 for txt, 2 for test" << endl;

    }else if (argv[1] == std::string("0")) ////////MODE SFML
    {
        std::cout << "SFML mode" << std::endl;
        DisplayGame game;
        game.DisplaySFML();

    }else if (argv[1] == std::string("1")) /////////////// MODE TEXTE
    {
        std::cout << "txt mode" << std::endl;
        termClear();
        Game game;
        txtLoop(game);
        termClear();
    }
    else if(argv[1] == std::string("2")){
        Box b;
        b.Test();
        Tileset ts;
        ts.Test();
        cout << "Tests réalisés avec succès !" << endl;
    }

    else /////////L'ARGUMENT NE CORRESPOND A AUCUN MODE
    {
        cerr << "The argument need to be 0 for SFML or 1 for txt" << endl;
    }
    return 0;
}

