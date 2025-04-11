/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include "World.h"
#include "Mario.h"

class Logger {
public:
    Logger(const std::string &logFileName);
    ~Logger();

    // Log the initial world layout (for all levels)
    void logInitialWorld(const World &world);

    // Log a single move:
    // level: current level (0-indexed)
    // row, col: Mario's current position
    // power: Mario's current power level (before the encounter)
    // action: description of what happened at this position
    // lives: number of lives after the encounter
    // coins: number of coins after the encounter
    // direction: direction Mario will move next ("UP", "DOWN", etc.)
    void logMove(int level, int row, int col, int power, const std::string &action,
                 int lives, int coins, const std::string &direction, const World &world);

    // Log the final outcome (win/lose and move count)
    void logOutcome(bool win, int moveCount);

    void close();

private:
    std::ofstream logFile;
};

#endif
