#include "NormalEnemy.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo
NormalEnemy::NormalEnemy(int health, int x, int y, int speed, int _droppedGold)
    : Enemy(health, x, y, speed, _droppedGold) {}

char NormalEnemy::getSymbol() { return 'N'; }

