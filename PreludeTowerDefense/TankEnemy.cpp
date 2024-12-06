#include "TankEnemy.h"
#include <iostream>
using namespace std;

// Constructor
TankEnemy::TankEnemy(int health, int x, int y, int speed, int droppedGold)
    : Enemy(health, x, y, speed, droppedGold) {}

// Override phương thức nhận sát thương
void TankEnemy::takeDamage(int damage) {
    int reducedDamage = damage / 2; // Giảm sát thương nhận xuống một nửa
    health -= reducedDamage;

    if (health < 0) {
        health = 0; // Đảm bảo máu không âm
    }

    if (health == 0) {
        cout << "TankEnemy at (" << position.getX() << ", " << position.getY() << ") is Dead" << endl;
        // Gọi phương thức để xóa quái khỏi danh sách khi máu bằng 0
        markAsDead();
    }

    cout << "TankEnemy at ("<< position.getX() << ", " << position.getY() << ") took reduced damage : " << reducedDamage
        << ", remaining health: " << health << endl;
}
