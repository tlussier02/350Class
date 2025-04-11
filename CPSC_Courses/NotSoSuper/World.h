/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#ifndef WORLD_H
#define WORLD_H
#include <string>
#include <fstream>
#include "Mario.h"

// Forward declaration of Mario to avoid circular dependency // this idea was brought up through coplit to solve pointer issues
class Mario;

class World {
public:
    World(const std::string& configFile);
    ~World();

    void simulateGame(const std::string& logFileName);
    void printWorld(std::ofstream& logFile) const;
    void printLevel(int level, std::ofstream &logFile) const;
    char getEncounter(int level, int row, int col) const;
    void setCell(int level, int row, int col, char value);
    void initializeWorld();
    void placeSpecialItems(int level);

    int getLevels() const { return levels; }
    int getGridSize() const { return gridSize; }


    int levels;
    int gridSize;
    int initialLives;
    int coinPercentage;
    int emptyPercentage;
    int goombaPercentage;
    int koopaPercentage;
    int mushroomPercentage;

    char*** world;
    Mario* mario;
};

#endif
