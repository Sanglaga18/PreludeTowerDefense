#pragma once
#include "Enemy.h"

class TankEnemy : public Enemy {
public:
    // Constructor
    TankEnemy(int health = 85, int x = 0, int y = 1, int speed = 1, int droppedGold = 200);

    // Override phương thức nhận sát thương
    void takeDamage(int damage) override;

    // Override phương thức getType
    char getType() const override {
        return 'T'; // 'T' đại diện cho TankEnemy
    }
};
