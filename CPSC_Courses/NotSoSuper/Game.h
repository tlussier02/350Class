/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#ifndef GAME_H
#define GAME_H

#include <string>
#include "World.h"
#include "Mario.h"
#include "Logger.h"

class Game {
public:
// constructor that initializes the game using the config file
    Game(const std::string& configFile);
    // destructor that cleans up what was used in the game
    ~Game();
// simulates the game and logs the results to the log file
    void simulateGame(const std::string& logFileName);

private:
// using pointers to manage dynamic memory allocation
    World* world;
    Mario* mario;
    Logger* logger;
};

#endif
