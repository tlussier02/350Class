/*
Full name: Mari Muramoto and Trevor Lussier
Student ID: 2444483 and 2445730
Chapman email: mmuramoto@chapman.edu and tlussier@chapman.edu
Course number and section: CPSC 350 01/04
Assignment or exercise number: PA2 Not so Super Mario Bros
*/

#include "Mario.h"
#include "World.h"
#include "Logger.h"
#include <cstdlib>

// Constructor that initializes Mario so that he starts with his lives and all objects or posiitons are at starting positions
Mario::Mario(int startLives) {
    lives = startLives;
    coins = 0;
    powerLevel = 0;
    row = 0;
    col = 0;
    currentLevel = 0;
    enemiesDefeatedThisLife = 0;
    world = nullptr; // Mario starts without a reference to the world
}

// Destructor to clean up what was used by Mario
Mario::~Mario() {
}

// Setting Mario's position on the grid
void Mario::setPosition(int newRow, int newCol) {
    row = newRow;
    col = newCol;
}

// Getting Mario's current row position
int Mario::getRow() const {
    return row;
}

// Getting Mario's current column position
int Mario::getCol() const {
    return col;
}

// Setting the current level Mario is on
void Mario::setCurrentLevel(int level) {
    currentLevel = level;
}

// Getting the current level Mario is on
int Mario::getCurrentLevel() const {
    return currentLevel;
}

// Adding coins to Mario's total and adding a life if he has 20 coins and resetting it if its used
void Mario::addCoins(int numCoins) {
    coins += numCoins;
    if (coins >= 20) {
        gainLife();
        coins -= 20;
    }
}

// Getting the number of coins Mario has
int Mario::getCoins() const {
    return coins;
}

// Decreasing Mario's life count and resetting enemies defeated
void Mario::loseLife() {
    lives--;
    enemiesDefeatedThisLife = 0;
}

// Increasing Mario's life count
void Mario::gainLife() {
    lives++;
}

// Getting the number of lives Mario has
int Mario::getLives() const {
    return lives;
}

// Increasing Mario's power level
void Mario::powerUp() {
    if (powerLevel < 2) {
        powerLevel++; // Increasing power level up to a maximum of 2
    }
}

// Decreasing Mario's power level and decreasing power if its above 0 but losing a life if the power level is 0
void Mario::powerDown() {
    if (powerLevel > 0) {
        powerLevel--;
    } else {
        loseLife();
        powerLevel = 0;
    }
}

// Getting Mario's current power level
int Mario::getPowerLevel() const {
    return powerLevel;
}

// Moving Mario to a random position on the grid// Coplit suggested the structure of this function
void Mario::moveRandom(int N) {
    int dir = rand() % 4; // Randomly choosing a direction
    switch (dir) {
        case 0:
            row = (row - 1 + N) % N; // Go up
            break;
        case 1:
            row = (row + 1) % N; // Go down
            break;
        case 2:
            col = (col - 1 + N) % N; // Go left
            break;
        case 3:
            col = (col + 1) % N; // Go right
            break;
    }
}

// Encounter with a regular enemy
bool Mario::encounterEnemy(char enemyType) {
    int chance = rand() % 100; // Random chance of winning or losing 
    int winThreshold = 0;
    if (enemyType == 'g') {
        winThreshold = 80; // 80% chance to defeat a Goomba
    } else if (enemyType == 'k') {
        winThreshold = 65; // 65% chance to defeat a Koopa
    } else {
        return true; // Nothing for other types
    }
    if (chance < winThreshold) {
        enemiesDefeatedThisLife++;
        if (enemiesDefeatedThisLife == 7) {
            gainLife(); // Gaining an extra life after defeating 7 enemies
            enemiesDefeatedThisLife = 0; // Resetting the count
        }
    } else {
        powerDown(); // Losing power if defeated
        if (lives <= 0) {
            return false; // Game over if no lives left
        }
    }
    return true;
}

// Encounter with a boss
bool Mario::encounterBoss(char enemyType) {
    if (enemyType != 'b') {
        return true; // Nothing happens if not a boss
    }
    while (true) {
        int chance = rand() % 100; // 50% chance to defeat the boss
        if (chance < 50) {
            return true; // Boss is dead
        } else {
            if (powerLevel == 2) {
                powerLevel = 0; // Lose all power if at max level
            } else {
                loseLife(); // Lose a life if not at max power
                powerLevel = 0; // Resetting power level
            }
            if (lives <= 0) {
                return false; // Game over if no lives left
            }
        }
    }
}

// Encounter with a warp pipe
bool Mario::encounterWarpPipe(char enemyType) {
    if (enemyType == 'w') {
        currentLevel++; // Moving to the next level
        if (world) {
            int N = world->getGridSize();
            setPosition(rand() % N, rand() % N); // Randomly placing Mario in the new level
        } else {
            setPosition(0, 0); // Default position if world is not set
        }
    }
    return true;
}

// Encounter with a mushroom
bool Mario::encounterMushroom(char enemyType) {
    if (enemyType == 'm') {
        powerUp(); // Increasing power level
    }
    return true;
}

// Encounter with a coin
bool Mario::encounterCoin(char enemyType) {
    if (enemyType == 'c') {
        addCoins(1); // Adding a coin to Mario's total
    }
    return true;
}

// Checking if Mario has won the game
bool Mario::winGame() {
    return (currentLevel >=(world ? world->levels : 0)); // Win if Mario reaches the last level
}

// Checking if Mario has lost the game
bool Mario::loseGame() {
    return (lives <= 0); // Lost if Mario has no lives left
}

// Setting the world Mario is in
void Mario::setWorld(World* w) {
    world = w; // Assigning the world to Mario
}
