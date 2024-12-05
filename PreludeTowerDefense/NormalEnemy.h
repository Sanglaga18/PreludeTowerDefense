#pragma once
#include "Enemy.h"

class NormalEnemy : public Enemy {
public:
    // Hàm khởi tạo nhận giá trị
    NormalEnemy(int health = 0, int x = 0, int y = 0, int speed = 0, int _droppedGold = 0);
    void move();
    char getSymbol() override;
};