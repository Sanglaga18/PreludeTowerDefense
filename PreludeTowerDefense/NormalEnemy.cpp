#include "NormalEnemy.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo
NormalEnemy::NormalEnemy(int health, int x, int y, int speed, int _droppedGold)
    : Enemy(health, x, y, speed, _droppedGold) {}

void NormalEnemy::move() {
    setPosition(getPosition().x + getSpeed(), getPosition().y);  // Cập nhật tọa độ y
    cout << "NormalEnemy moved to position: (" << getPosition().x << ", " << getPosition().y << ")" << endl;
}
