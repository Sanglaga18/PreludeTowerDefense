#include "Player.h"
#include <iostream>
using namespace std;

// Constructor
Player::Player(int initialHealth, int initialGold)
    : health(initialHealth), gold(initialGold) {}

// Getter
int Player::getHealth() const {
    return health;
}

int Player::getGold() const {
    return gold;
}

// Setter
void Player::setHealth(int newHealth) {
    if (newHealth < 0) {
        cout << "Health cannot be negative. Setting to 0." << endl;
        health = 0;
    }
    else {
        health = newHealth;
    }
}

void Player::setGold(int newGold) {
    if (newGold < 0) {
        cout << "Gold cannot be negative. Setting to 0." << endl;
        gold = 0;
    }
    else {
        gold = newGold;
    }
}

// Phương thức giảm máu khi bị tấn công
void Player::takeDamage(int damage) {
    if (damage < 0) {
        cout << "Damage cannot be negative!" << endl;
        return;
    }

    health -= damage;
    if (health < 0) {
        health = 0;
    }
    //cout << "Player took " << damage << " damage. Remaining health: " << health << endl;
}

// Phương thức thêm vàng
void Player::addGold(int amount) {
    if (amount < 0) {
        cout << "Cannot add negative gold!" << endl;
        return;
    }

    gold += amount;
    cout << "Player gained " << amount << " gold. Total gold: " << gold << endl;
}
