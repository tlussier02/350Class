/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#include "Logger.h"
#include <iostream>

// constructor that opens the log file and checks if it was opened correctly
Logger::Logger(const std::string &logFileName) {
    logFile.open(logFileName);
    if (!logFile) {
        std::cerr << "Error opening log file: " << logFileName << std::endl;
        exit(1);
    }
}
// destructor that closes the log file if it was opened
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
// logging the initial world
void Logger::logInitialWorld(const World &world) {
    // printing the full layout of each level as the initial world
    world.printWorld(logFile);
}
// logging a move from mario
void Logger::logMove(int level, int row, int col, int power, const std::string &action,
                     int lives, int coins, const std::string &direction, const World &world) {
    logFile << "Level: " << (level + 1)
            << ", Position: (" << row << ", " << col << ")"
            << ", Power: " << power
            << ", Action: " << action
            << ", Lives: " << lives
            << ", Coins: " << coins
            << ", Next Move: " << direction << "\n";
            // printing the level after the move
    world.printLevel(level,logFile);
    logFile << "\n";
}
// logging the outcome of the game
void Logger::logOutcome(bool win, int moveCount) {
    logFile << "Game " << (win ? "Won" : "Lost") << " in " << moveCount << " moves.\n";
}
// closing the log file
void Logger::close() {
    if (logFile.is_open())
        logFile.close();
}
