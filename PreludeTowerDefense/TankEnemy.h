﻿#pragma once
#include "Enemy.h"

class TankEnemy : public Enemy {
public:
    // Hàm khởi tạo nhận giá trị
    TankEnemy(int health = 0, int x = 0, int y = 0, int speed = 0, int _droppedGold = 0, char _symbol = 'T');
    void move();
};
