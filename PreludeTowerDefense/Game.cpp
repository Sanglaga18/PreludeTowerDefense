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
void Game::spawnEnemies() {
    int n = 0;
    if (difficulty == "Easy") n = 3;
    else if (difficulty == "Medium") n = 5;
    else if (difficulty == "Hard") n = 7;

    set<int> usedCols; 

    for (int i = 0; i < n; i++) {
        int col;
        do {
            col = rand() % mapLength;
        } while (usedCols.find(col) != usedCols.end());

        usedCols.insert(col); 

        int type = rand() % 3; // 0: Enemy, 1: Fast, 2: Tank
        if (type == 0) enemies.push_back(new NormalEnemy(100, -col, 1, 1, 100));
        else if (type == 1) enemies.push_back(new FastEnemy(100, -col, 1, 1, 100));
        else enemies.push_back(new TankEnemy(100, -col, 1, 1, 100));
    }
}
void Game::addTower(Tower* tower) {
    towers.push_back(tower);
}
void Game::drawMap() {
    cout << "Map:\n";

    cout << "   ";
    for (int col = 0; col < mapLength; col++) {
        cout << col << " ";
    }
    cout << endl;

    for (int row = 0; row < 3; row++) {
        cout << row << " |"; 

        for (int col = 0; col < mapLength; col++) {
            bool printed = false;

            for (auto& tower : towers) {
                if (tower->getPosition().x == col && tower->getPosition().y == row) {
                    cout << tower->getSymbol() << "|";
                    printed = true;
                    break;
                }
            }

            if (!printed) {
                for (auto& enemy : enemies) {
                    if (enemy->getPosition().x == col && enemy->getPosition().y == row) {
                        cout << enemy->getSymbol() << "|";
                        printed = true;
                        break;
                    }
                }
            }

            if (!printed) {
                cout << " |"; 
            }
        }
        cout << endl;

        cout << "  -";
        for (int col = 0; col < mapLength; col++) {
            cout << "--"; 
        }
        cout << endl;
    }
}
void Game::placeTower() {
    cout << "Do you want to buy a tower? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        cout << "Player's gold: " << player.getGold() << endl;
        cout << "Choose tower type (1: Cannon - $200, 2: Power - $300): ";
        char type;
        cin >> type;

        int towerCost = 0;

        if (type == '1') {
            towerCost = 200;
        }
        else if (type == '2') {
            towerCost = 300;
        }
        else {
            cout << "Invalid tower type! Please try again!" << endl;
            placeTower();
            return;
        }

        if (player.getGold() < towerCost) {
            cout << "Not enough gold to buy this tower! Please try again!" << endl;
            placeTower();
            return;
        }

        cout << "Enter the x-coordinate (0 to " << mapLength - 1 << "): ";
        char x_char;
        cin >> x_char;
        int x = x_char - '0'; 

        cout << "Enter the y-coordinate (0 or 2): ";
        char y_char;
        cin >> y_char;
        int y = y_char - '0'; 

        if (x >= 0 && x < mapLength && (y == 0 || y == 2)) {
            if (!isPositionOccupied(x, y)) {
                Tower* tower = nullptr;

                if (type == '1') {
                    tower = new CannonTower(20, 5, Position(x, y));
                }
                else if (type == '2') {
                    tower = new PowerTower(30, 3, Position(x, y));
                }

                if (tower) {
                    addTower(tower); 
                    tower->printInfo();
                }
                player.subGold(towerCost);
                drawMap();
                placeTower();
            }
            else {
                cout << "There is already a tower at this position! Please choose another location." << endl;
                placeTower();
            }
        }
        else {
            cout << "Invalid coordinates! Please try again!" << endl;
            placeTower();
        }
    }
}

bool Game::isPositionOccupied(int x, int y) {
    for (const auto& tower : towers) {
        if (tower->getPosition().x == x && tower->getPosition().y == y) {
            return true;
        }
    }
    return false;
}

void Game::updateGame() {
    for (auto& enemy : enemies) {
        enemy->move();
        if (enemy->getPosition().x >= mapLength) {
            player.takeDamage(1);
            cout << "An enemy reached the end! Lives left: " << player.getHealth() << endl;
        }
    }
    for (auto& tower : towers) {
        tower->attack(enemies);
    }

    for (auto it = enemies.begin(); it != enemies.end();) {
        if ((*it)->getHealth() == 0 || (*it)->getPosition().x >= mapLength) {
            player.addGold((*it)->getDroppedGold());
            it = enemies.erase(it);
        }
        else {
            ++it;
        }
    }
    drawMap();
}
const string red = "\033[31m";
const string yellow = "\033[33m";
const string reset = "\033[0m";
void Game::run() {
    spawnEnemies();
    drawMap();
    while (true) {
        placeTower();
        updateGame();
        if (player.getHealth() == 0) {
            cout << red;
            cout << " *****       *     *       * *****      *****  *       * ***** *****   " << endl;
            cout << "*     *     * *    * *   * * *         *     *  *     *  *     *    *  " << endl;
            cout << "*         *******  *   *   * ***       *     *   *   *   ***   *****   " << endl;
            cout << "*    ***  *     *  *       * *         *     *    * *    *     *  *    " << endl;
            cout << " *****   *       * *       * *****      *****      *     ***** *    *  " << endl;
            cout << reset;
            break;
        }
        if (enemies.empty()) {
            cout << yellow;
            cout << "*       *  *****  *     *     *           * ***** *   * " << endl;
            cout << "  *   *   *     * *     *      *         *    *   **  * " << endl;
            cout << "    *     *     * *     *       *   *   *     *   * * * " << endl;
            cout << "    *     *     * *     *        * * * *      *   *  ** " << endl;
            cout << "    *      *****   *****          *   *     ***** *   * " << endl;
            cout << reset;
            break;
        }
    }
}

