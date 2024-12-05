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
    virtual ~Enemy() = default;
    virtual void move();

    Enemy(const Position& pos, int hp, int speed, int gold); // Constructor matching the argument list
    void takeDamage(int damage); // Phương thức nhận sát thương
    int getDroppedGold();   // Getter cho droppedGold
    int getHealth();        // Getter cho health
    int getSpeed();
    Position getPosition(); // Getter cho position
    void setPosition(const Position& pos); // Setter cho position
    void setPosition(int x, int y);
};