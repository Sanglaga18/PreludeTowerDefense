#include "PowerTower.h"
#include <iostream>

// Constructor
PowerTower::PowerTower(const Position& position, int damage, int range, int cost)
    : Tower( damage, range, cost, position) {}

// Destructor
PowerTower::~PowerTower() {}

// Attack implementation
void PowerTower::attack(std::vector<Enemy*>& enemies) {
    //cout << "PowerTower attacking with double damage!" << endl;

    Enemy* target = nullptr;
    int maxColumn = -1;

    // Tìm kẻ địch xa nhất trong phạm vi
    for (Enemy* enemy : enemies) {
        if (position.distanceTo(enemy->getPosition()) <= range) {
            if (enemy->getPosition().y > maxColumn) {
                maxColumn = enemy->getPosition().y;
                target = enemy;  // Lưu trỏ tới enemy
            }
        }
    }

    // Nếu có kẻ địch trong phạm vi, tấn công kẻ xa nhất
    if (target) {
        int doubleDamage = damage * 2;
        cout << "PowerTower at (" << position.getX() << ", " << position.getY() << ") attacking enemies in range!" << endl;
        target->takeDamage(doubleDamage);  // Sử dụng "->" thay cho "."
        /*cout << "Enemy at (" << target->getPosition().x << ", " << target->getPosition().y
            << ") took " << doubleDamage << " damage!" << endl;*/
    }
}

