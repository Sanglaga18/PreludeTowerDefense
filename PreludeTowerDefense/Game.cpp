#include "Game.h"
#include "CannonTower.h"
#include "PowerTower.h"
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



void Game::handleUserInput() {
    while (true) {
        cout << endl;
        cout << "Player Health: " << player.getHealth() << ", Gold: " << player.getGold() << endl;
        cout << "Menu Options:" << endl;
        cout << "1: Buy more tower" << endl;
        cout << "2: Sell tower" << endl;
        cout << "3: Start next turn" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                buyTower();
                break;
            case 2:
                sellTower();
                break;
            case 3:
                return; // Exit the menu and start the next turn
                cout << endl;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Game::updateGameState() {
    //di chuyen
    for (auto it = enemies.begin(); it != enemies.end();) {
        Enemy* enemy = *it;
        Position pos = enemy->getPosition();

        //Den cuoi vi tri chua
        if (pos.getY() >= mapLength - 1) {
            //tru mau
            player.takeDamage(1); 

            //xoa khi den dc vi tri cuoi
            delete enemy;
            it = enemies.erase(it);
        } else {
            enemy->move(); //tat ca nhung dua con lai di chuyen
            ++it;
        }
    }

    //ythap tan cong
    for (Tower* tower : towers) {
        tower->attack(enemies);
    }
}

void Game::renderMap() {
    //khoi tao ban do
    cout << endl;
    for (auto& row : map) {
        fill(row.begin(), row.end(), ' ');
    }

    // dat thap
    for (Tower* tower : towers) {
        Position pos = tower->getPosition();
        if (dynamic_cast<PowerTower*>(tower)) {
            map[pos.getX()][pos.getY()] = '@';
        } else if (dynamic_cast<CannonTower*>(tower)) {
            map[pos.getX()][pos.getY()] = '#';
        }
    }

    //dat ke dich
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

    //hien thi map
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


void Game::buyTower() {
    cout << endl;
    cout << "Buying a new tower..." << endl;
    cout << "Enter the type of tower (1 for CannonTower, 2 for PowerTower): ";
    int towerType;
    cin >> towerType;

    int x, y;
    cout << "Enter the position X to place the tower: ";
    cin >> x;
    cout << "Enter the position Y to place the tower: ";
    cin >> y;

    //check vi tri
    if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size() || (x != 0 && x != 2)) {
        cout << "Invalid position. Towers can only be placed in rows 0 and 2, and within valid column range." << endl;
        return;
    }

    // check du tien
    if (player.getGold() >= 10) //gia tien
        player.addGold(-10); // tru tien

        if (towerType == 1) {
            addTower(new CannonTower(10, 2, Position(x, y)));
        } else if (towerType == 2) {
            addTower(new PowerTower(20, 5, Position(x, y))); 
        } else {
            cout << "Invalid tower type." << endl;
            player.addGold(10); //hoan tien neu mua sai
        }

        cout << "Tower bought successfully!" << endl;
    } else {
        cout << "Not enough gold to buy a tower." << endl;
    }
}

void Game::sellTower() {
    cout << endl;
    cout << "Selling a tower..." << endl;
    cout << "Enter the position X of the tower to sell: ";
    int x;
    cin >> x;
    cout << "Enter the position Y of the tower to sell: ";
    int y;
    cin >> y;

    
    if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size() || (x != 0 && x != 2)) {
        cout << "Invalid position. Towers can only be placed in rows 0 and 2, and within valid column range." << endl;
        return;
    }

    auto it = find_if(towers.begin(), towers.end(), [x, y](Tower* tower) {
        Position pos = tower->getPosition();
        return pos.getX() == x && pos.getY() == y;
    });

    if (it != towers.end()) {
        Tower* tower = *it;
        towers.erase(it);
        delete tower;
        player.addGold(5); //ban thap duoc 5 gold
        cout << "Tower sold successfully!" << endl;
    } else {
        cout << "No tower found at the specified position." << endl;
    }
}

bool Game::isGameOver(){
    return player.getHealth() <= 0;
}