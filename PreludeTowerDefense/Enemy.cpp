#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int _health, int _x, int _y, int _speed, int _droppedGold) {
    health = _health;
    position.x = _x;
    position.y = _y;
    speed = _speed;
    droppedGold = _droppedGold;
}
// Phương thức di chuyển kẻ địch
void Enemy::move() {
    position.y += speed;    // Cập nhật tọa độ y và đi chuyển sang phải
    cout << "Enemy moved to position: (" << position.x << ", " << position.y << ")" << endl;
}

// Phương thức nhận sát thương
void Enemy::takeDamage(int damage) {
    health -= damage;       // Giảm máu
    if (health < 0) {
        health = 0;         // Đảm bảo máu không âm
    }
    cout << "Enemy took damage: " << damage << ", remaining health: " << health << endl;
}

// Getter cho droppedGold
int Enemy::getDroppedGold() {
    return droppedGold;
}

// Getter cho health
int Enemy::getHealth() {
    return health;
}

// Getter cho position
Position Enemy::getPosition() const {
    return position;  // Trả về đối tượng position của Enemy
}