#pragma once
#include "Enemy.h"

class TankEnemy : public Enemy {
public:
    // Hàm khởi tạo nhận giá trị
    TankEnemy(const Position& pos, int hp, int speed, int gold);
    void move() override;
};
