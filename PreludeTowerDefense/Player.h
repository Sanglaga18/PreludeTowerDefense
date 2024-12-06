#include <iostream>
#include "Position.h"
using namespace std;
#pragma once


class Player {
private:
    int health;
    int gold;

public:
    //khoi tao mau, vang, vi tri
    Player(int initialHealth = 20, int initialGold = 35);
    //get
    int getHealth() const;
    int getGold() const;
    //set
    void setHealth(int newHealth);
    void setGold(int newGold);

    //phuong thuc
    void takeDamage(int damage);
    void addGold(int amount);
};

