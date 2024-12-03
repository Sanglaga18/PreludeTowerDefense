#include <iostream>
#include "Position.h"
using namespace std;
#pragma once


class Player {
private:
    int health;
    int gold;
    Position position;

public:
    //khoi tao mau, vang, vi tri
    Player(int initialHealth, int initialGold, Position initialPosition);
    //get
    int getHealth() const;
    int getGold() const;
    Position getPosition() const;
    //set
    void setHealth(int newHealth);
    void setGold(int newGold);
    void setPosition(Position newPosition);

    //phuong thuc
    void takeDamage(int damage);
    void addGold(int amount);
};

