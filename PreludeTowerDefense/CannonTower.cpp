#include "CannonTower.h"
#include <iostream>

// Constructor
CannonTower::CannonTower(int damage, int range, const Position& position)
    : Tower(damage, range, position) {}

// Destructor
CannonTower::~CannonTower() {}

void CannonTower::attack(std::vector<Enemy*>& enemies) {
    cout << "CannonTower attacking enemies in range!" << endl;

    for (Enemy* enemy : enemies) {
        // Kiểm tra kẻ địch trong phạm vi
        if (position.distanceTo(enemy->getPosition()) <= range) {
            enemy->takeDamage(damage); // Gây sát thương lên tất cả kẻ địch trong phạm vi
            cout << "Enemy at (" << enemy->getPosition().x << ", " << enemy->getPosition().y
                << ") took " << damage << " damage!" << endl;
        }
    }
}
