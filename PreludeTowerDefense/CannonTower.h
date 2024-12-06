#pragma once
#include "Tower.h"

class CannonTower : public Tower {
public:
  
    CannonTower(int damage = 20, int range = 2, const Position& position = Position(0, 0));

 
    ~CannonTower();

    
     void attack(std::vector<Enemy*>& enemies) override;
};
