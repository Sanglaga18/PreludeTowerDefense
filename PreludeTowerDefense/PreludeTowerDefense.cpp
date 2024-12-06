#include <iostream>
#include <ctime>
#include "Enemy.h"
#include "FastEnemy.h"
#include "Position.h"
#include "Game.h"
using namespace std;
int main() {

	srand(time(0)); // Khởi tạo seed ngẫu nhiên

	Game game;

	int cheDo = 0;
	const string red = "\033[31m";
	const string yellow = "\033[33m";
	const string reset = "\033[0m";
	cout << yellow << "*******  *****  *           * ***** *****      *****  ***** ***** ***** *   *  *****  ***** " << red << "             " << endl;
	cout << yellow << "   *    *     *  *         *  *     *    *     *    * *     *     *     **  * **    * *     " << red << "  * *   * *  " << endl;
	cout << yellow << "   *    *     *   *   *   *   ***   *****      *    * ***   ***   ***   * * *    **   ***   " << red << " *    *    * " << endl;
	cout << yellow << "   *    *     *    * * * *    *     *  *       *    * *     *     *     *  ** *    ** *     " << red << "  *       *  " << endl;
	cout << yellow << "   *     *****      *   *     ***** *    *     *****  ***** *     ***** *   *  *****  ***** " << red << "     * *     " << endl;
	cout << reset;
	cout << "\nChoose difficulty level (1: Easy, 2: Medium, 3: Hard): ";
	
	while (true) {
		cout << "Your choice: ";
		cin >> cheDo;
		

		if (cheDo >= 1 && cheDo <= 3) {
			if (cheDo == 1) {
				game = Game(200, 3, 10, 3);  // vàng, máu, cột trên bản đồ
				break;
			}
			if (cheDo == 2) {
				game = Game(200, 3, 10, 6);  // vàng, máu, cột trên bản đồ
				break;
			}
			if (cheDo == 3) {
				game = Game(200, 3, 10, 9);  // vàng, máu, cột trên bản đồ
				break;
			}
		}
		else {
			cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
		}
	}

	// Bắt đầu trò chơi
	game.play();
	system("pause");
	return 0;
}