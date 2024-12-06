#pragma once
#include "Tower.h"

class CannonTower : public Tower {
public:
    // Constructor
    //CannonTower(int damage = 20, int range = 5, int cost = 30, const Position& position = Position(0, 0));
    CannonTower(const Position& position, int damage = 25, int range = 2, int cost = 30);

    // Destructor
    ~CannonTower();

    // Override the attack method
    void attack(std::vector<Enemy*>& enemies) override;

    // Override phương thức getType
    char getType() const override {
        return 'C'; // 'C' đại diện cho CannonTower
    }
};
