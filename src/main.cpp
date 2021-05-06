#include <iostream>
#include <string>
#include "Core/Game.h"

#include "Core/Entity/FiniteStateMachine/StateMachine.h"
#include "Core/Entity/FiniteStateMachine/EnemyStates.h"


int main(int argc, char *argv[])
{

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
    else if (argv[1] == std::string("debug"))
    {
        
    }

    else /////////L'ARGUMENT NE CORRESPOND A AUCUN MODE
    {
        std::cerr << "The argument need to be 0 for SFML or 1 for txt"
                  << std::endl;
    }
    return 0;
}
