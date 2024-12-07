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
    int cost;      // Tiền của tháp
    Position position; // Vị trí tháp trên bản đồ (dòng, cột).

public:
    // Constructors & Destructor
    Tower(int damage = 1, int range = 1, int cost = 1, const Position& position = Position(0, 0));
    virtual ~Tower();

    // Getters
    int getDamage();
    int getRange();
    int getCost();
    Position getPosition();

    // Setters
    void setDamage(int damage);
    void setRange(int range);
    void setCost(int cost);
    void setPosition(const Position& position);

    void printInfo();

    // Hàm trả về kiểu tháp
    virtual char getType() const = 0;  // Hàm trừu tượng, mỗi tháp con phải ghi đè phương thức này

    // Abstract method
    virtual void attack(std::vector<Enemy*>& enemies) = 0; // Hàm tấn công (thuần ảo).
};
