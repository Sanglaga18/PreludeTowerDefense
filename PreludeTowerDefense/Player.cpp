#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(int initialHealth, int initialGold)
    : health(20), gold(35) {}


int Player::getHealth() const {
    return health;
}
int Player::getGold() const {
    return gold;
}


void Player::setHealth(int newHealth) {
    health = newHealth;
}
void Player::setGold(int newGold) {
    gold = newGold;
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