#pragma once
#include "Enemy.h"

class FastEnemy : public Enemy {
public:
    // Constructor
    FastEnemy(int health = 100, int x = 0, int y = 1, int speed = 1, int droppedGold = 150);

    // Override phương thức di chuyển
    void move() override;

    // Override phương thức getType
    char getType() const override {
        return 'F'; // 'F' đại diện cho FastEnemy
    }
};
