#include "PowerTower.h"
#include <iostream>
using namespace std;

// Constructor
PowerTower::PowerTower(int damage, int range, const Position& position)
    : Tower(damage, range, position), turnCounter(0) {}

// Destructor
PowerTower::~PowerTower() {}

// Attack implementation
void PowerTower::attack(std::vector<Enemy*>& enemies) {
    turnCounter++;
    if (turnCounter % 2 != 0) {
        cout << "PowerTower is recharging and will attack next turn." << endl;
        return;
    }

    cout << "PowerTower attacking with double damage!" << endl;

    for (Enemy* enemy : enemies) {
        if (position.distanceTo(enemy->getPosition()) <= range) {
            int doubleDamage = damage * 2;
            enemy->takeDamage(doubleDamage); 
            cout << "Enemy at (" << enemy->getPosition().getX() << ", " << enemy->getPosition().getY()
                 << ") took " << doubleDamage << " damage!" << endl;
            break; 
        }
    }
}