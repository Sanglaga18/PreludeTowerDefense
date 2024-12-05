#include "CannonTower.h"
#include <iostream>

// Constructor
CannonTower::CannonTower(int damage, int range, const Position& position)
    : Tower(damage, range, position) {}

// Destructor
CannonTower::~CannonTower() {}

// Attack implementation
void CannonTower::attack(std::vector<Enemy*>& enemies) {
    cout << "CannonTower attacking enemies in range!" << endl;
  
    for (Enemy* enemy : enemies) {
        // Kiểm tra kẻ địch trong phạm vi
        if (enemy->getPosition().x >= 0 && position.distanceTo(enemy->getPosition()) <= range) {
            enemy->takeDamage(damage); // Gây sát thương lên tất cả kẻ địch trong phạm vi
        }
    }
    

    /*Ví dụ
    * 
    Vị trí của tháp : (0, 2) (hàng 0, cột 2)
    Tầm bắn : 3 (phạm vi là 3 ô, nghĩa là tháp có thể tấn công các kẻ địch trong phạm vi 3 ô tính từ vị trí của tháp).
    Vì tháp nằm ở hàng 0, phạm vi tấn công sẽ là các ô trong hàng 1, tức là ngay dưới tháp.
    Phạm vi cột :
        Cột bên trái |2 - 3| = cột 0 (Giới hạn ma trận)
        Cột bên phải |2 + 3 | = cột 5
    Các ô nằm trong phạm vi tấn công: (1, 0), (1, 1), (1, 2), (1, 3), (1, 4), (1, 5)

          0 1 2 3 4 5 6 7 8 9
        0| | |C| | | | | | | |
        ----------------------
        1|x|x|x|x|x|x| | | | |
        -------------------- -
        2| | | | | | | | | | |
        ----------------------
    */

}
char CannonTower::getSymbol() {return 'C';}