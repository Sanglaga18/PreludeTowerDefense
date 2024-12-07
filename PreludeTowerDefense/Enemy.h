#include <iostream>
#include "Position.h"
using namespace std;
#pragma once

class Enemy {
protected:
    int health;             // Máu của kẻ địch
    Position position;      // Vị trí trên bản đồ
    int speed;              // Tốc độ di chuyển (theo ô)
    int droppedGold;        // Tiền rơi ra khi bị hạ
    bool isDead;            // Trạng thái chết của kẻ địch

public:
    Enemy(int _health = 0, int _x = 0, int _y = 0, int _speed = 0, int _droppedGold = 0);
    virtual void move();            // Phương thức di chuyển kẻ địch
    virtual void takeDamage(int damage); // Phương thức nhận sát thương
    // Hàm trả về kiểu Enemy
    virtual char getType() const = 0;  // Hàm trừu tượng, mỗi Enemy con phải ghi đè phương thức này
    int getDroppedGold();   // Getter cho droppedGold
    int getHealth();        // Getter cho health
    int getSpeed();
    Position getPosition() const; // Getter cho position


    void setHealth(int newHealth);
    void setPosition(int x, int y);

    // Getter và Setter cho isDead
    bool enemyIsDead() const { return isDead; }
    void markAsDead() { isDead = true; }
};
