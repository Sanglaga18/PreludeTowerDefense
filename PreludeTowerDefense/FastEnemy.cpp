#include "FastEnemy.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo
FastEnemy::FastEnemy(int health, int x, int y, int speed, int _droppedGold, char _symbol)
    : Enemy(health, x, y, speed * 2, _droppedGold, _symbol) {}

// Ghi đè phương thức di chuyển
void FastEnemy::move() {
    setPosition(getPosition().x + getSpeed(), getPosition().y);  // Cập nhật tọa độ y
    cout << "FastEnemy moved to position: (" << getPosition().x << ", " << getPosition().y << ")" << endl;
}

