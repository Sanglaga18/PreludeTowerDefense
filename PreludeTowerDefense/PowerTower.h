#pragma once
#include "Tower.h"

class PowerTower : public Tower {
private:
    int turnCounter; // dem so luot ban, moi 2 luot ban 1 lan
public:
    
    PowerTower(int damage = 30, int range = 1, const Position& position = Position(0, 0));

  
    ~PowerTower();

   
    void attack(std::vector<Enemy*>& enemies) override;
};
