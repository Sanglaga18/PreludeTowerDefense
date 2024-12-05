#pragma once
#include "Enemy.h"

class FastEnemy : public Enemy {
public:
    // Hàm khởi tạo nhận giá trị
    FastEnemy(const Position& pos, int hp, int speed, int gold);
    void move() override;
};