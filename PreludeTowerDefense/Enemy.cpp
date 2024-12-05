#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int _health, int _x, int _y, int _speed, int _droppedGold, char _symbol) {
    health = _health;
    position.x = _x;
    position.y = _y;
    speed = _speed;
    droppedGold = _droppedGold;
    symbol = _symbol;
}
// Phương thức di chuyển kẻ địch
void Enemy::move() {
    position.x += speed;    // Cập nhật tọa độ y và đi chuyển sang phải
}

// Phương thức nhận sát thương
void Enemy::takeDamage(int damage) {
    health -= damage;       // Giảm máu
    if (health < 0) {
        health = 0;         // Đảm bảo máu không âm
    }
    cout << "Enemy at position (" << position.x << ", " << position.y << ")" << " took damage : " << damage << ", remaining health : " << health << endl;
}

// Getter cho droppedGold
int Enemy::getDroppedGold() {
    return droppedGold;
}

// Getter cho health
int Enemy::getHealth() {
    return health;
}

int Enemy::getSpeed() {
    return speed;
}

void Enemy::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}
// Getter cho position
Position Enemy::getPosition() const {
    return position;  // Trả về đối tượng position của Enemy

}

char Enemy::getSymbol() {
    return symbol;
}
