#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "Enemy.h"
#include "FastEnemy.h"
#include "TankEnemy.h"
#include "Position.h"
#include "Game.h"
#include "CannonTower.h"
#include "PowerTower.h"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    Game game(10, "Normal");
    int turnCounter = 0;

   
    
    game.addEnemy(new Enemy(Position(1, 0), 100, 1, 10));
   
    
    while (true) {
        turnCounter++;
        system("cls"); //refresh man hinh
        cout << "-----------------------" << endl;
        cout << "Turn: " << turnCounter << endl;

        //random enemy spawn
        if (turnCounter % 3 == 0) {
            int enemyType = rand() % 2; 
            if (enemyType == 0) {
                game.addEnemy(new FastEnemy(Position(1, 0), 100, 1, 10)); // FastEnemy
            } else {
                game.addEnemy(new TankEnemy(Position(1, 0), 200, 1, 20)); // TankEnemy
            }
            cout << "A new enemy has spawned!" << endl;
        }

        game.updateGameState();
        game.renderMap();
        game.handleUserInput();


        if (game.isGameOver()) {
            cout << "Game over!" << endl;
            break;
        }
    }

    return 0;
}