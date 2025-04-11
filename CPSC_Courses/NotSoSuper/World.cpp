/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#include "World.h"
#include "Mario.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// constructor that initiiazes the world using configFile
World::World(const std::string& configFile) {
    std::ifstream file(configFile);
    if (!file) {
        std::cerr << "Error opening configuration file." << std::endl;
        exit(1);
    }
    // reading the configuration parameters from the file
    file >> levels >> gridSize >> initialLives;
    file >> coinPercentage >> emptyPercentage >> goombaPercentage >> koopaPercentage >> mushroomPercentage;
    // checking if the percentages are valid
    if (coinPercentage + emptyPercentage + goombaPercentage + koopaPercentage + mushroomPercentage != 100) {
        std::cerr << "Percentages must sum to 100." << std::endl;
        exit(1);
    }
    file.close();
    // random number generator for random items
    srand(time(0));
    initializeWorld();
    // creating a new Mario object
    mario = new Mario(initialLives);
}

// iniztializes the world grid with items based on the percentages
void World::initializeWorld() {
    world = new char**[levels];
    for (int l = 0; l < levels; ++l) {
        world[l] = new char*[gridSize];
        for (int i = 0; i < gridSize; ++i) {
            world[l][i] = new char[gridSize];
            for (int j = 0; j < gridSize; ++j) {
                int randNum = rand() % 100;
                if (randNum < coinPercentage)
                    world[l][i][j] = 'c';
                else if (randNum < coinPercentage + emptyPercentage)
                    world[l][i][j] = 'x';
                else if (randNum < coinPercentage + emptyPercentage + goombaPercentage)
                    world[l][i][j] = 'g';
                else if (randNum < coinPercentage + emptyPercentage + goombaPercentage + koopaPercentage)
                    world[l][i][j] = 'k';
                else
                    world[l][i][j] = 'm';
            }
        }
        // this is for items like the boss or warp
        placeSpecialItems(l);
    }
}

// adding boss and warp pipes in the level
void World::placeSpecialItems(int level) {
    int bossRow = rand() % gridSize;
    int bossCol = rand() % gridSize;
    world[level][bossRow][bossCol] = 'b';
    // placing the warp block only if it isnt the last level
    if (level < levels - 1) {
        int warpRow, warpCol;
        do {
            warpRow = rand() % gridSize;
            warpCol = rand() % gridSize;
        } while (world[level][warpRow][warpCol] == 'b');
        world[level][warpRow][warpCol] = 'w';
    }
}

// printing world to a log file for debugging
void World::printWorld(std::ofstream& logFile) const {
    for (int l = 0; l < levels; ++l) {
        logFile << "Level " << l + 1 << ":\n";
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                logFile << world[l][i][j] << ' ';
            }
            logFile << '\n';
        }
        logFile << "\n";
    }
}
// printing a specific level to a log file for debugging
void World::printLevel(int level, std::ofstream &logfile)const{
    logfile <<"level"<< (level +1) << ":\n";
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            logfile << world[level][i][j] << ' ';
        }
        logfile << '\n';
    }
    logfile << "\n";
}
// getting the encounter at a specific cell
char World::getEncounter(int level, int row, int col) const {
    return world[level][row][col];
}
// setting the encounter at a specific cell
void World::setCell(int level, int row, int col, char value) {
    world[level][row][col] = value;
}
// making destructor to clean the memory
World::~World() {
    for (int l = 0; l < levels; ++l) {
        for (int i = 0; i < gridSize; ++i) {
            delete[] world[l][i];
        }
        delete[] world[l];
    }
    delete[] world;
    delete mario;
}
