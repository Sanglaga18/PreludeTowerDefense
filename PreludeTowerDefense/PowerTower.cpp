#include "PowerTower.h"
#include <iostream>
using namespace std;

void PowerTower::attack(std::vector<Enemy*>& enemies) {
    cout << "PowerTower attacking with double damage!" << endl;
    Enemy* target = nullptr;
    int maxColumn = -1;

    // Tìm kẻ địch xa nhất trong phạm vi
    for (Enemy* enemy : enemies) {
        if (position.distanceTo(enemy->getPosition()) <= range) {
            if (enemy->getPosition().getY() > maxColumn) {
                maxColumn = enemy->getPosition().getY();
                target = enemy;
            }
        }
    }

    // Nếu có kẻ địch trong phạm vi, tấn công kẻ xa nhất
    if (target) {
        int doubleDamage = damage * 2;
        target->takeDamage(doubleDamage);
        cout << "Enemy at (" << target->getPosition().getX() << ", " << target->getPosition().getY()
            << ") took " << doubleDamage << " damage!" << endl;
    }
}