#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(Position initialPosition)
    : health(20), gold(35), position(initialPosition) {}


int Player::getHealth() const {
    return health;
}
int Player::getGold() const {
    return gold;
}
Position Player::getPosition() const {
    return position;
}


void Player::setHealth(int newHealth) {
    health = newHealth;
}
void Player::setGold(int newGold) {
    gold = newGold;
}
void Player::setPosition(Position newPosition) {
    position = newPosition;
}


void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

void Player::addGold(int amount) {
    gold += amount;
}