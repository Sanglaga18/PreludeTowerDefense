#include <iostream>
#include <cmath>
using namespace std;
#pragma once

class Position {
public:
    int x; // Tọa độ x
    int y; // Tọa độ y

    Position(int _x = 0, int _y = 0);

    // Getters
    int getX() const;
    int getY() const;
    // Setters
    
    void setX(int _x);
    void setY(int _y);

    // Phương thức tính khoảng cách Manhattan đến vị trí khác
    int distanceTo(const Position& other) const;
    Position& operator=(const Position& other);
};