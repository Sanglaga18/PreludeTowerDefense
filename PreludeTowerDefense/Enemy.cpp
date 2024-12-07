#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int _health, int _x, int _y, int _speed, int _droppedGold)
    : health(_health), position(_x, _y), speed(_speed), droppedGold(_droppedGold), isDead(false) {}

// Phương thức di chuyển kẻ địch
void Enemy::move() {
        position.x += speed;  // Cập nhật tọa độ x (cột) và di chuyển sang phải
        //cout << "Enemy moved to position: (" << position.x << ", " << position.y << ")" << endl;
}

// Phương thức nhận sát thương
void Enemy::takeDamage(int damage) {
    health -= damage;       // Giảm máu
    if (health < 0) {
        health = 0;         // Đảm bảo máu không âm
    }

    if (health == 0) {
        cout << "Enemy at (" << position.getX() << ", " << position.getY() << ") is Dead" << endl;
        // Gọi phương thức để xóa quái khỏi danh sách khi máu bằng 0
        markAsDead();
    }
    else {
        //cout << "Enemy took damage: " << damage << ", remaining health: " << health << endl;
        cout << "Enemy at (" << position.getX() << ", " << position.getY() << ") took reduced damage : " << damage
            << ", remaining health: " << health << endl;
    }
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

// Getter cho position
Position Enemy::getPosition() const {
    return position;  // Trả về đối tượng position của Enemy

}

void Enemy::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void Enemy::setHealth(int newHealth) {
    if (newHealth < 0) {
        health = 0;  // Nếu giá trị mới nhỏ hơn 0, đặt health về 0
    }
    else {
        health = newHealth; // Gán giá trị mới cho health
    }
}
