#pragma once
#include "Tower.h"

class PowerTower : public Tower {
public:
    // Constructor
    PowerTower(int damage = 30, int range = 3, const Position& position = Position(0, 0));

    // Destructor
    ~PowerTower();

    // Override the attack method
    void attack(std::vector<Enemy*>& enemies) override;
};
