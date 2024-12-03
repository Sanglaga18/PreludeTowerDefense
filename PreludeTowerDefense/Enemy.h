#include <iostream>
#include "Position.h"
using namespace std;
#pragma once

class Enemy {
private:
    int health;             // Máu của kẻ địch
    Position position;      // Vị trí trên bản đồ
    int speed;              // Tốc độ di chuyển (theo ô)
    int droppedGold;        // Tiền rơi ra khi bị hạ

public:
    Enemy(int _health = 0, int _x = 0, int _y = 0, int _speed = 0, int _droppedGold = 0);
    void move();            // Phương thức di chuyển kẻ địch
    void takeDamage(int damage); // Phương thức nhận sát thương
    int getDroppedGold();   // Getter cho droppedGold
    int getHealth();        // Getter cho health
    int getSpeed();
    void setPosition(int x, int y);
    Position getPosition() const; // Getter cho position
};
