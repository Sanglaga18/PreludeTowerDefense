#include "Enemy.h"
#include <iostream>
using namespace std;


Enemy::Enemy(const Position& pos, int hp, int speed, int gold)
    : position(pos), health(hp), speed(speed), droppedGold(gold) {}

// Phương thức di chuyển kẻ địch
void Enemy::move() {
    position.setY(position.getY() + speed);    // Cập nhật tọa độ y và đi chuyển sang phải
    cout << "Enemy moved to position: (" << position.getX() << ", " << position.getY() << ")" << endl;
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
int Enemy::getHealth(){
    return health;
}

int Enemy::getSpeed(){
    return speed;
}

Position Enemy::getPosition(){
    return position;
}

void Enemy::setPosition(const Position& pos) {
    position = pos;
}

void Enemy::setPosition(int x, int y) {
    position.setX(x);
    position.setY(y);
}