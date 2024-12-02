#pragma once
#include "TankEnemy.h"
// Định nghĩa hàm khởi tạo
TankEnemy::TankEnemy(int health, int x, int y, int speed, int _droppedGold)
    : Enemy(health * 2, x, y, speed, _droppedGold) {
    // TankEnemy có máu gấp đôi kẻ địch thông thường
}

// Ghi đè phương thức di chuyển
void TankEnemy::move() {
    setPosition(getPosition().x, getPosition().y - getSpeed());  // Cập nhật tọa độ y
    cout << "FastEnemy moved to position: (" << getPosition().x << ", " << getPosition().y << ")" << endl;
}
