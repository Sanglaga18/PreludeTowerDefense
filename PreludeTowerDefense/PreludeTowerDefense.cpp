#include <iostream>
#include "Enemy.h"
#include "FastEnemy.h"
#include "TankEnemy.h"
#include "Position.h"
#include "Game.h"
#include "CannonTower.h"
#include "PowerTower.h"
using namespace std;

int main() {
    Game game(10, "Normal");

    // Add some towers and enemies for testing
    game.addTower(new CannonTower(10, 2, Position(0, 2)));
    game.addEnemy(new FastEnemy(Position(1, 0), 100, 1, 10));
    game.addEnemy(new TankEnemy(Position(1, 2), 100, 1, 20));
    
    
    
    while (true) {
        game.updateGameState();
        game.renderMap();
        game.displayGameState();
        game.handleUserInput();

        // Check for exit condition
        char userInput;
        cout << "Enter 'q' to quit or any other key to continue: ";
        cin >> userInput;
        if (userInput == 'q' || userInput == 'Q') {
            break;
        }
    }

    return 0;
}