#include "TankEnemy.h"
#include <iostream>
using namespace std;


TankEnemy::TankEnemy(const Position& pos, int hp, int speed, int gold)
    : Enemy(pos, hp*2, speed, gold) {}


void TankEnemy::move() {
    Position pos = getPosition();
    pos.setY(pos.getY() + getSpeed()); 
    setPosition(pos);
    cout << "TankEnemy moved to position: (" << pos.getX() << ", " << pos.getY() << ")" << endl;
}