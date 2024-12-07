#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Tower.h"
#include "CannonTower.h"
#include "PowerTower.h"
#include "Enemy.h"
#include "FastEnemy.h"
#include "TankEnemy.h"
using namespace std;

class Game {
private:
    Player player;
    vector<Tower*> towers;
    vector<Enemy*> enemies;
    vector<vector<string>> map;
    int mapLength;
    int difficulty;
    int totalEnemiesSpawned;
public:
    // Constructor
    Game(int initialGold = 100, int initialHealth = 10, int mapLength = 10, int difficulty = 3, int totalEnemiesSpawned = 0);

    // Destructor
    ~Game();

    // Game setup
    void initializeMap();
    void displayMap();
    void displayStatus();
    void chooseDifficulty();

    // Gameplay
    void addTower(Tower* tower, int x, int y);
    void spawnEnemy();
    void updateGame();
    void play();

    // Helpers
    bool isValidPosition(int x, int y);

    bool checkWin();
    bool checkLose();

    // Getter cho totalEnemiesSpawned
    int getTotalEnemiesSpawned() const;

    // Setter cho totalEnemiesSpawned
    void setTotalEnemiesSpawned(int count);
};
