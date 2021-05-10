#include <iostream>
#include <string>
#include <stdlib.h>
#include "Core/Game.h"


int main(int argc, char *argv[])
{
    srand(time(NULL));

    if (argc == 1 || argc > 2) //////CHECK DU NOMBRE D'ARGUMENTS
    {
        std::cerr << "You need one argument : 0 for SFML, 1 for txt, 2 for test"
                  << std::endl;
    }
    else if (argv[1] == std::string("0")) ////////MODE SFML
    {
        std::cout << "SFML mode" << std::endl;
        Game game;
        game.Run(0);
    }
    else if (argv[1] == std::string("1")) /////////////// MODE TEXTE
    {
        std::cout << "txt mode" << std::endl;
        termClear();
        Game game;
        game.Run(1);
        termClear();
    }
    else if (argv[1] == std::string("2"))
    {
        std::cout << "===== TEST DE REGRESSION =====" << std::endl
                  << std::endl;
        Game game;
        game.Run(2);
    }

    else /////////L'ARGUMENT NE CORRESPOND A AUCUN MODE
    {
        std::cerr << "The argument need to be 0 for SFML or 1 for txt or 2 for tests."
                  << std::endl;
    }
    return 0;
}
