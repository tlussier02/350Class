/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#ifndef MARIO_H
#define MARIO_H
#include <cstdlib>

// forward declaration
class World;
class Mario {
public:
// constructor that initializes Mario with the given amount of lives
    Mario(int startLives);
    // destructor cleans what was used from Mario
    ~Mario();

    // setting the position and getting the current row and column of Mario
    void setPosition(int newRow, int newCol);
    int getRow() const;
    int getCol() const;

    // adding components of the game to be used in Mario.cpp
    void setCurrentLevel(int level);
    int getCurrentLevel() const;

    void addCoins(int numCoins);
    int getCoins() const;

    void loseLife();
    void gainLife();
    int getLives() const;

    void powerUp();
    void powerDown();
    int getPowerLevel() const;

    void moveRandom(int N);

    bool encounterEnemy(char enemyType);
    bool encounterBoss(char enemyType);
    bool encounterWarpPipe(char enemyType);
    bool encounterMushroom(char enemyType);
    bool encounterCoin(char enemyType);
    bool winGame();
    bool loseGame();

    void setWorld(World* w);

private:
    int row;
    int col;
    int currentLevel;
    int lives;
    int coins;
    int powerLevel;
    int enemiesDefeatedThisLife;
    World* world; // pointer to the world
};

#endif
