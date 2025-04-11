/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#include "Game.h"
#include <iostream>

int main(int argc, char** argv) {
    // Using argc and argv to check if theres enough arguments
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <configFile> <logFile>" << std::endl;
        return 1;
    }
    
   // Creating a new game object using the config file
    Game game(argv[1]);
    
   // Simulating the game and logging the results to the log file
    game.simulateGame(argv[2]);
    
    return 0;
}
