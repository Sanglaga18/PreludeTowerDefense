#include "Tower.h"

// Constructor có tham số
Tower::Tower(int damage, int range, const Position& position)
    : damage(damage), range(range), position(position) {}

// Destructor
Tower::~Tower() {}

// Getters
int Tower::getDamage(){
    return damage;
}

int Tower::getRange(){
    return range;
}

Position Tower::getPosition(){
    return position;
}

// Setters
void Tower::setDamage(int damage) {
    if (damage < 0) {
        cerr << "Damage cannot be negative!" << endl;
        return;
    }
    this->damage = damage;
}

void Tower::setRange(int range) {
    if (range < 0) {
        cerr << "Range cannot be negative!" << endl;
        return;
    }
    this->range = range;
}

void Tower::setPosition(const Position& position) {
    if (position.x < 0 || position.y < 0) {
        cerr << "Position cannot have negative coordinates!" << endl;
        return;
    }
    this->position = position;
}

void Tower::printInfo() {
    cout << "Tower Info:" << endl;
    cout << "Damage: " << damage << endl;
    cout << "Range: " << range << endl;
    cout << "Position: (" << position.getX() << ", " << position.getY() << ")" << endl;
}
