#include "FastEnemy.h"
#include <iostream>
using namespace std;

// Constructor
FastEnemy::FastEnemy(int health, int x, int y, int speed, int droppedGold)
    : Enemy(health, x, y, speed, droppedGold) {}

// Override phương thức di chuyển
void FastEnemy::move() {
        position.x += (2 * speed); // Di chuyển nhanh hơn bằng cách nhân đôi tốc độ
        //cout << "FastEnemy moved to position: (" << position.x << ", " << position.y << ")" << endl;
}
