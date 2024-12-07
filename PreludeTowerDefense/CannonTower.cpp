#include "CannonTower.h"
#include <iostream>

// Constructor
CannonTower::CannonTower(const Position& position, int damage, int range, int cost)
    : Tower(damage, range, cost, position) {}

// Destructor
CannonTower::~CannonTower() {}

// Attack implementation
void CannonTower::attack(std::vector<Enemy*>& enemies) {

    for (Enemy* enemy : enemies) {
        Position enemyPos = enemy->getPosition();
        int dist = position.distanceTo(enemyPos);

        if (dist <= range) {
            cout << "CannonTower at (" << position.getX() << ", " << position.getY() << ") attacking enemies in range!" << endl;
            enemy->takeDamage(damage);  // Gây sát thương cho kẻ địch
            /*cout << "Enemy at (" << enemy->getPosition().x << ", " << enemy->getPosition().y
                << ") took " << damage << " damage!" << endl;*/
        }
    }
}


