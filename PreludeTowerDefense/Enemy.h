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
    char symbol;
public:
    Enemy(int _health = 0, int _x = 0, int _y = 0, int _speed = 0, int _droppedGold = 0, char _symbol = 'N');
    virtual void move() = 0;            // Phương thức di chuyển kẻ địch
    void takeDamage(int damage); // Phương thức nhận sát thương
    int getDroppedGold();   // Getter cho droppedGold
    int getHealth();        // Getter cho health
    int getSpeed();
    void setPosition(int x, int y);
    Position getPosition() const; // Getter cho position
    char getSymbol();
};
