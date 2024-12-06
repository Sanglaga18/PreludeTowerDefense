#include "FastEnemy.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo
FastEnemy::FastEnemy(const Position& pos, int hp, int speed, int gold)
    : Enemy(pos, hp, speed, gold) {}

// Ghi đè phương thức di chuyển
void FastEnemy::move() {
    Position pos = getPosition();
    int newY = pos.getY() + getSpeed() * 2;
    if (newY >= 10) { // Assuming 10 is the last position of the row
        newY = 9;
    }
    pos.setY(newY);  // Cập nhật tọa độ y, di chuyển gấp đôi tốc độ
    setPosition(pos);
    cout << "FastEnemy moved to position: (" << pos.getX() << ", " << pos.getY() << ")" << endl;
}