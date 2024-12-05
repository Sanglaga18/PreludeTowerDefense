#include "PowerTower.h"
#include <iostream>

// Constructor
PowerTower::PowerTower(int damage, int range, const Position& position)
    : Tower(damage, range, position) {}

// Destructor
PowerTower::~PowerTower() {}

// Attack implementation
void PowerTower::attack(std::vector<Enemy*>& enemies) {
    cout << "PowerTower attacking with double damage!" << endl;

    Enemy* target = nullptr;
    int maxColumn = -1;

    // Tìm kẻ địch xa nhất trong phạm vi
    for (Enemy* enemy : enemies) {
        if (enemy->getPosition().x >= 0 && position.distanceTo(enemy->getPosition()) <= range) {
            if (enemy->getPosition().y > maxColumn) {
                maxColumn = enemy->getPosition().y;
                target = enemy;
            }
        }
    }

    // Nếu có kẻ địch trong phạm vi, tấn công kẻ xa nhất
    if (target) {
        int doubleDamage = damage * 2;
        target->takeDamage(doubleDamage);
    }
    
}
char PowerTower::getSymbol() { return 'P'; }