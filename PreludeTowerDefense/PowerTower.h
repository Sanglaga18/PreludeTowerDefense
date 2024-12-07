#pragma once
#include "Tower.h"

class PowerTower : public Tower {
public:
    // Constructor
    //PowerTower(int damage = 30, int range = 3, int cost = 40,const Position& position = Position(0, 0));
    PowerTower(const Position& position, int damage = 20, int range = 2, int cost = 40);

    // Destructor
    ~PowerTower();

    // Override the attack method
    void attack(std::vector<Enemy*>& enemies) override;

    // Override phương thức getType
    char getType() const override {
        return 'P'; // 'P' đại diện cho PowerTower
    }
};
