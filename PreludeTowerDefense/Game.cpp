#include "Game.h"
#include "TankEnemy.h"
#include "FastEnemy.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor
Game::Game(int length, string difficulty)
    : player(100, 10), mapLength(length), difficulty(difficulty), map(3, vector<char>(mapLength, ' ')) {
    // Khởi tạo bản đồ với chiều dài mapLength và chiều rộng cố định là 3
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

void Game::displayGameState() {
    // Display player info
    cout << "Player Health: " << player.getHealth() << ", Gold: " << player.getGold() << endl;

    // Display towers
    cout << "Towers:" << endl;
    for (Tower* tower : towers) {
        tower->printInfo();
    }

    // Display enemies
    cout << "Enemies:" << endl;
    for (Enemy* enemy : enemies) {
        cout << "Enemy at (" << enemy->getPosition().getX() << ", " << enemy->getPosition().getY()
             << "), Health: " << enemy->getHealth() << endl;
    }

    // Display options
}

void Game::handleUserInput() {
    // Handle user input (this is a placeholder implementation)
    cout << "Handling user input..." << endl;
}

void Game::updateGameState() {
    // Move enemies
    for (auto it = enemies.begin(); it != enemies.end();) {
        Enemy* enemy = *it;
        if (enemy->getHealth() <= 0) {
            // Add dropped gold to player's gold
            player.addGold(enemy->getDroppedGold());

            // Remove dead enemy
            delete enemy;
            it = enemies.erase(it);
        }
        else {
            enemy->move(); // Call the move method for each enemy
            ++it;
        }
    }

    // Towers attack enemies
    for (Tower* tower : towers) {
        tower->attack(enemies);
    }
}

void Game::renderMap() {
    // Clear the map
    for (auto& row : map) {
        fill(row.begin(), row.end(), ' ');
    }

    // Place towers on the map
    for (Tower* tower : towers) {
        Position pos = tower->getPosition();
        map[pos.getX()][pos.getY()] = 'T';
    }

    // Place enemies on the map
    for (Enemy* enemy : enemies) {
        Position pos = enemy->getPosition();
        if (dynamic_cast<TankEnemy*>(enemy)) {
            map[pos.getX()][pos.getY()] = 'D';
        } else if (dynamic_cast<FastEnemy*>(enemy)) {
            map[pos.getX()][pos.getY()] = 'F';
        } else {
            map[pos.getX()][pos.getY()] = 'E';
        }
    }

    // Display the map
    cout << "  ";
    for (int i = 0; i < mapLength; ++i) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i < map.size(); ++i) {
        cout << i << ' ';
        for (char cell : map[i]) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

void Game::addTower(Tower* tower) {
    towers.push_back(tower);
}

void Game::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}