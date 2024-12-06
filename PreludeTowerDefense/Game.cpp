#include "Game.h"
#include "FastEnemy.h"
#include "TankEnemy.h"
#include "CannonTower.h"
#include "PowerTower.h"
// Constructor
Game::Game(int length, string difficulty)
    : player(100, 1000), mapLength(length), difficulty(difficulty) {
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

// In Game.cpp, here are the implementations
void Game::displayGameState() {
    // Display current game status
    cout << "Game Status:" << endl;
    cout << "Player Health: " << player.getHealth() << endl;
    cout << "Player Gold: " << player.getGold() << endl;

    // Display towers
    cout << "Towers (" << towers.size() << "):" << endl;
    for (size_t i = 0; i < towers.size(); ++i) {
        cout << "Tower " << i + 1 << " at ("
            << towers[i]->getPosition().x << ", "
            << towers[i]->getPosition().y << ")" << endl;
    }

    // Display enemies
    cout << "Enemies (" << enemies.size() << "):" << endl;
    for (size_t i = 0; i < enemies.size(); ++i) {
        cout << "Enemy " << i + 1 << " at ("
            << enemies[i]->getPosition().x << ", "
            << enemies[i]->getPosition().y
            << ") - Health: " << enemies[i]->getHealth() << endl;
    }
}

void Game::handleUserInput() {
    int choice;
    cout << "\n--- Game Menu ---" << endl;
    cout << "1. Add Tower" << endl;
    cout << "2. Add Enemy" << endl;
    cout << "3. View Game State" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int x, y, towerType;
        cout << "Enter tower type (1: Cannon, 2: Power): ";
        cin >> towerType;
        cout << "Enter tower x coordinate: ";
        cin >> x;
        cout << "Enter tower y coordinate: ";
        cin >> y;

        if (towerType == 1) {
            addTower(new CannonTower(20, 5, Position(x, y)));
        }
        else if (towerType == 2) {
            addTower(new PowerTower(30, 3, Position(x, y)));
        }
        break;
    }
    case 2: {
        int x, y, enemyType;
        cout << "Enter enemy type (1: Normal, 2: Fast, 3: Tank): ";
        cin >> enemyType;
        cout << "Enter enemy x coordinate: ";
        cin >> x;
        cout << "Enter enemy y coordinate: ";
        cin >> y;

        if (enemyType == 1) {
            addEnemy(new Enemy(20, x, y, 1, 50));
        }
        else if (enemyType == 2) {
            addEnemy(new FastEnemy(20, x, y, 2, 75));
        }
        else if (enemyType == 3) {
            addEnemy(new TankEnemy(20, x, y, 1, 100));
        }
        break;
    }
    case 3:
        displayGameState();
        break;
    case 4:
        cout << "Exiting game..." << endl;
        exit(0);
    default:
        cout << "Invalid choice!" << endl;
    }
}

void Game::updateGameState() {
    // Move enemies
    for (auto it = enemies.begin(); it != enemies.end(); ) {
        (*it)->move();

        // Check if enemy is out of map or dead
        if ((*it)->getPosition().y < 0 || (*it)->getHealth() <= 0) {
            // If enemy dies, player gets gold
            if ((*it)->getHealth() <= 0) {
                player.addGold((*it)->getDroppedGold());
            }

            // Remove and free memory
            delete* it;
            it = enemies.erase(it);
        }
        else {
            ++it;
        }
    }

    // Attack by towers
    for (Tower* tower : towers) {
        tower->attack(enemies);
    }
}

void Game::renderMap() {
    // Clear the map
    for (auto& row : map) {
        fill(row.begin(), row.end(), 0);
    }

    // Place towers on map
    for (Tower* tower : towers) {
        Position pos = tower->getPosition();
        if (pos.x >= 0 && pos.x < map.size() &&
            pos.y >= 0 && pos.y < mapLength) {
            map[pos.x][pos.y] = 1; // Represent tower with 1
        }
    }

    // Place enemies on map
    for (Enemy* enemy : enemies) {
        Position pos = enemy->getPosition();
        if (pos.x >= 0 && pos.x < map.size() &&
            pos.y >= 0 && pos.y < mapLength) {
            map[pos.x][pos.y] = 2; // Represent enemy with 2
        }
    }

    // Render map
    cout << "Game Map:" << endl;
    for (const auto& row : map) {
        for (int cell : row) {
            switch (cell) {
            case 0: cout << ". "; break; // Empty cell
            case 1: cout << "T "; break; // Tower
            case 2: cout << "E "; break; // Enemy
            default: cout << "? "; break;
            }
        }
        cout << endl;
    }
}

void Game::addTower(Tower* tower) {
    // Check if the player has enough gold
    int towerCost = 50; // Example cost
    if (player.getGold() >= towerCost) {
        towers.push_back(tower);
        player.setGold(player.getGold() - towerCost);
        cout << "Tower added successfully!" << endl;
    }
    else {
        cout << "Not enough gold to add tower!" << endl;
        delete tower; // Prevent memory leak
    }
}

void Game::addEnemy(Enemy* enemy) {
    // Add enemy to the game
    enemies.push_back(enemy);
    cout << "Enemy added successfully!" << endl;
}
Player Game::getPlayer() {
    return player;
}
