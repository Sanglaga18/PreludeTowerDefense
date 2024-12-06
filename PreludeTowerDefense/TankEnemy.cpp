#pragma once
#include "TankEnemy.h"
// Định nghĩa hàm khởi tạo
TankEnemy::TankEnemy(int health, int x, int y, int speed, int _droppedGold, char _symbol)
    : Enemy(health * 2, x, y, speed, _droppedGold, _symbol) {
    // TankEnemy có máu gấp đôi kẻ địch thông thường
}

// Ghi đè phương thức di chuyển
void TankEnemy::move() {
    setPosition(getPosition().x + getSpeed(), getPosition().y);  // Cập nhật tọa độ y
    cout << "TankEnemy moved to position: (" << getPosition().x << ", " << getPosition().y << ")" << endl;
}

