#pragma once
#include "Tower.h"

class CannonTower : public Tower {
public:
    // Constructor
    CannonTower(int damage = 20, int range = 5, const Position& position = Position(0, 0));

    // Destructor
    ~CannonTower();

    // Override the attack method
    void attack(std::vector<Enemy*>& enemies) override;
    char getSymbol() override;
};
