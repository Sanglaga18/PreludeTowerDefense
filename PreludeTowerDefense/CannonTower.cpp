#include "CannonTower.h"
#include <iostream>
using namespace std;

// Constructor
CannonTower::CannonTower(int damage, int range, const Position& position)
    : Tower(damage, range, position) {}

// Destructor
CannonTower::~CannonTower() {}

// Attack implementation
void CannonTower::attack(std::vector<Enemy*>& enemies) {
    cout << "CannonTower attacking enemies in range!" << endl;

    for (Enemy* enemy : enemies) {
        // Check if the enemy is within range using Manhattan distance
        if (position.distanceTo(enemy->getPosition()) <= range) {
            enemy->takeDamage(damage); // Deal damage to the first enemy within range
            cout << "Enemy at (" << enemy->getPosition().getX() << ", " << enemy->getPosition().getY()
                 << ") took " << damage << " damage!" << endl;
            break; // Stop after damaging the first enemy
        }
    }
}