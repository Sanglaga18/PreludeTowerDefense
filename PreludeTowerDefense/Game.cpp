#include "Game.h"

// Constructor
Game::Game(int length, string difficulty)
    : player(100, 10), mapLength(length), difficulty(difficulty) {
    // Khởi tạo bản đồ với chiều dài mapLength và chiều rộng cố định là 3
    map = vector<vector<int>>(3, vector<int>(mapLength, 0));
}

// Destructor
Game::~Game() {
    // Giải phóng bộ nhớ cho danh sách tháp và kẻ địch
    for (Tower* tower : towers) {
        delete tower;
    }
    for (Enemy* enemy : enemies) {
        delete enemy;
    }
}


