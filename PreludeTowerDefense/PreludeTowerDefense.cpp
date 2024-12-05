#include <iostream>
#include <iomanip> 
#include "Enemy.h"
#include "FastEnemy.h"
#include "Position.h"
#include "Game.h"
using namespace std;
int main() {
    string difficulty;
    cout << endl;
    const string red = "\033[31m";
    const string yellow = "\033[33m";
    const string reset = "\033[0m";
    cout << yellow << "*******  *****  *           * ***** *****      *****  ***** ***** ***** *   *  *****  ***** " << red << "             " << endl;
    cout << yellow << "   *    *     *  *         *  *     *    *     *    * *     *     *     **  * **    * *     " << red << "  * *   * *  " << endl;
    cout << yellow << "   *    *     *   *   *   *   ***   *****      *    * ***   ***   ***   * * *    **   ***   " << red << " *    *    * " << endl;
    cout << yellow << "   *    *     *    * * * *    *     *  *       *    * *     *     *     *  ** *    ** *     " << red << "  *       *  " << endl;
    cout << yellow << "   *     *****      *   *     ***** *    *     *****  ***** *     ***** *   *  *****  ***** " << red << "     * *     " << endl;
    cout << reset;
    cout << "Choose difficulty level (1: Easy, 2: Medium, 3: Hard): ";

    char choice;
    cin >> choice;

    switch (choice) {
    case '1':
        difficulty = "Easy";
        break;
    case '2':
        difficulty = "Medium";
        break;
    case '3':
        difficulty = "Hard";
        break;
    default:
        cout << "Invalid choice. Defaulting to 'Easy'.\n";
        difficulty = "Easy";
        break;
    }
	Game game(10, difficulty);
	game.run();
	system("pause");
	return 0;
}