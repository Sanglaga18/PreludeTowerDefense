#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Position.h"
using namespace std;
#pragma once

class Tower {
protected:
    int damage;    // Sát thương của tháp.
    int range;     // Tầm bắn của tháp.
    Position position; // Vị trí tháp trên bản đồ (dòng, cột).

public:
    // Constructors & Destructor
    Tower(int damage = 0, int range = 0, const Position& position = Position(0, 0));
    virtual ~Tower();

    // Getters
    int getDamage();
    int getRange();
    Position getPosition();

    // Setters
    void setDamage(int damage);
    void setRange(int range);
    void setPosition(const Position& position);

    void printInfo();

    // Abstract method
    virtual void attack(std::vector<Enemy*>& enemies) = 0; // Hàm tấn công (thuần ảo).
    virtual char getSymbol() = 0; // Hàm ảo để lấy ký hiệu
};
