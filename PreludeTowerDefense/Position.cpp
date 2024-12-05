#include "Position.h"

Position::Position(int _x, int _y) : x(_x), y(_y) {}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

// Setters
void Position::setX(int _x) {
    x = _x;
}

void Position::setY(int _y) {
    y = _y;
}

// Phương thức tính khoảng cách Manhattan
int Position::distanceTo(const Position& other) const {
    return abs(x - other.x) + abs(y - other.y);
}

Position& Position::operator=(const Position& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}