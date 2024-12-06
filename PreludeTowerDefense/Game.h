#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <set>
#include "Player.h"
#include "Tower.h"
#include "CannonTower.h"
#include "PowerTower.h"
#include "Enemy.h"
#include "FastEnemy.h"
#include "TankEnemy.h"
#include "NormalEnemy.h"

using namespace std;

class Game {
private:
    Player player;                           // Người chơi
    vector<Tower*> towers;                   // Danh sách các tháp
    vector<Enemy*> enemies;                  // Danh sách các kẻ địch
    int mapLength;                           // Chiều dài bản đồ
    vector<vector<int>> map;                 // Bản đồ trò chơi (ma trận 2D)
    string difficulty;                       // Độ khó (Thường hoặc Khó)

public:
    // Constructor
    Game(int length = 10, string difficulty = "Easy");

    // Destructor
    ~Game();

    // Phương thức
    void spawnEnemies();
    void addTower(Tower* tower);
    void drawMap();
    void placeTower();
    bool isPositionOccupied(int x, int y);
    void updateGame();
    void run();
};
