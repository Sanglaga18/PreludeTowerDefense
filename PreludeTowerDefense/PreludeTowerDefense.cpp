#include <iostream>
#include "Enemy.h"
#include "Position.h"
using namespace std;
int main() {
	Enemy enemy(100, 1, 10, 1, 100);    // Tạo một kẻ địch với 100 máu, vị trí (1, 10), tốc độ 1, và tiền rơi 100
	enemy.move();                       // Kẻ địch di chuyển
	enemy.takeDamage(10);               // Kẻ địch nhận sát thương
	cout << "Gold dropped: " << enemy.getDroppedGold() << endl;
	system("pause");
	return 0;
}