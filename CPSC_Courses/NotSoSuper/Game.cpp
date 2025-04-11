/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// constructor that initializes the game using the config file
Game::Game(const std::string& configFile) {
    world = new World(configFile);
    mario = new Mario(world->initialLives); // creating mario with initial lives
    mario->setWorld(world); // set the world for Mario
    logger = nullptr; // will be created in simulateGame
}
// destructor that cleans up what was used in the game
Game::~Game() {
    if (logger) {
        logger->close();
        delete logger;
    }
    delete mario;
    delete world;
}
// simulates the game and logs the results to the log file
void Game::simulateGame(const std::string& logFileName) {
    logger = new Logger(logFileName);
    logger->logInitialWorld(*world);

    int moveCount = 0;
    // Main simulation loop: runs until Mario wins or loses
    while (!mario->loseGame() && !mario->winGame()) {
        int curLevel = mario->getCurrentLevel();
        if (curLevel >= world->levels) {
            break;
        }
        // getting the positions of mario and the encounter
        int row = mario->getRow();
        int col = mario->getCol();
        char cell = world->getEncounter(curLevel, row, col);

        // using the letters that correspond with the objects to add game text based on what is happening
        std::string action;
        if (cell == 'c') {
            if (mario->encounterCoin(cell)) {
                action = "Mario collects a coin";
                world->setCell(curLevel, row, col, 'x');
            } else {
                action = "Mario loses a life collecting coin";
            }
        } else if (cell == 'g' || cell == 'k') {
            if (mario->encounterEnemy(cell)) {
                action = "Mario defeats the enemy";
                world->setCell(curLevel, row, col, 'x');
            } else {
                action = "Mario loses a life fighting enemy";
            }
        } else if (cell == 'b') {
            if (mario->encounterBoss(cell)) {
                action = "Mario defeats the boss and clears level";
                world->setCell(curLevel, row, col, 'x');
                mario->setCurrentLevel(curLevel + 1);
                mario->setPosition(rand() % world->getGridSize(), rand() % world->getGridSize());
            } else {
                action = "Mario loses a life fighting the boss";
            }
        } else if (cell == 'm') {
            if (mario->encounterMushroom(cell)) {
                action = "Mario gains a power level from a mushroom";
                world->setCell(curLevel, row, col, 'x');
            } else {
                action = "Mario loses a life from mushroom encounter";
            }
        } else if (cell == 'w') {
            if (mario->encounterWarpPipe(cell)) {
                action = "Mario enters the warp pipe and advances to the next level";
                mario->setCurrentLevel(curLevel + 1);
                mario->setPosition(rand() % world->getGridSize(), rand() % world->getGridSize());
            }
        } else {
            action = "Nothing happens at this location";
        }

        // Determining next move direction
        int oldRow = mario->getRow();
        int oldCol = mario->getCol();
        mario->moveRandom(world->getGridSize());
        int newRow = mario->getRow();
        int newCol = mario->getCol();
        std::string direction;
        if (newRow < oldRow)
            direction = "UP";
        else if (newRow > oldRow)
            direction = "DOWN";
        else if (newCol < oldCol)
            direction = "LEFT";
        else if (newCol > oldCol)
            direction = "RIGHT";
        else
            direction = "STAY PUT";

        moveCount++;

        // Logging the move
        logger->logMove(curLevel, row, col, mario->getPowerLevel(),
                        action, mario->getLives(), mario->getCoins(), direction, *world);

        // Checking win/lose conditions
        if (mario->loseGame()) {
            logger->logOutcome(false, moveCount);
            break;
        }
        if (mario->winGame()) {
            logger->logOutcome(true, moveCount);
            break;
        }
    }
    logger->close();
}
