#include "TankEnemy.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo
TankEnemy::TankEnemy(const Position& pos, int hp, int speed, int gold)
    : Enemy(pos, hp*2, speed, gold) {}

// Ghi đè phương thức di chuyển
void TankEnemy::move() {
    Position pos = getPosition();
    pos.setY(pos.getY() - getSpeed());  // Cập nhật tọa độ y
    setPosition(pos);
    cout << "TankEnemy moved to position: (" << pos.getX() << ", " << pos.getY() << ")" << endl;
}