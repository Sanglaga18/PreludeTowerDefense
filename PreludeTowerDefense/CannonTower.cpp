#include "CannonTower.h"
#include <iostream>
using namespace std;

//khoitao
CannonTower::CannonTower(int damage, int range, const Position& position)
    : Tower(damage, range, position) {}

CannonTower::~CannonTower() {}

// Attack 
void CannonTower::attack(std::vector<Enemy*>& enemies) {
    cout << "CannonTower attacking enemies in range!" << endl;

    for (Enemy* enemy : enemies) {
        // Manhattan
        if (position.distanceTo(enemy->getPosition()) <= range) {
            enemy->takeDamage(damage); 
            cout << "Enemy at (" << enemy->getPosition().getX() << ", " << enemy->getPosition().getY()
                 << ") took " << damage << " damage!" << endl;
            break; // chi ban dua thu 1
        }
    }
}