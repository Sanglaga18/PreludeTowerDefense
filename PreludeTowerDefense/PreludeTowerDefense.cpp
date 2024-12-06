#include <iostream>
#include "Enemy.h"
#include "FastEnemy.h"
#include "Position.h"
#include "Game.h"
using namespace std;
int main() {
    Game game(10, "Normal");

    while (game.getPlayer().getHealth() > 0) {
        game.renderMap();
        game.handleUserInput();
        game.updateGameState();
    }

    cout << "Game Over!" << endl;
    return 0;
}