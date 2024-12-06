#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "Tower.h"
#include "Enemy.h"

using namespace std;

class Game {
private:
    Player player;                           // Người chơi
    vector<Tower*> towers;                   // Danh sách các tháp
    vector<Enemy*> enemies;                  // Danh sách các kẻ địch
    int mapLength;                           // Chiều dài bản đồ
    vector<vector<char>> map;                 // Bản đồ trò chơi (ma trận 2D)
    string difficulty;                       // Độ khó (Thường hoặc Khó)

public:
    // Constructor
    Game(int length = 10, string difficulty = "Normal");

    // Destructor
    ~Game();

    // Phương thức
    void handleUserInput();
    void updateGameState();
    void renderMap();
    void addTower(Tower* tower);
    void addEnemy(Enemy* enemy);
    void buyTower();
    void sellTower();
    bool isGameOver();
};
