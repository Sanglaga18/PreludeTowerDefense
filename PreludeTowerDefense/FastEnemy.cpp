#include "FastEnemy.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo
FastEnemy::FastEnemy(int health, int x, int y, int speed, int _droppedGold)
    : Enemy(health, x, y, speed, _droppedGold) {}

// Ghi đè phương thức di chuyển
void FastEnemy::move() {
    setPosition(getPosition().x, getPosition().y - getSpeed() * 2);  // Cập nhật tọa độ y
    cout << "FastEnemy moved to position: (" << getPosition().x << ", " << getPosition().y << ")" << endl;
}
