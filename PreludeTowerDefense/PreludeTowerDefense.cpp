#include <iostream>
using namespace std;
class Position {
public:
    int x; // Tọa độ x
    int y; // Tọa độ y

    Position(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
};

class Enemy {
private:
    int health;             // Máu của kẻ địch
    Position position;      // Vị trí trên bản đồ
    int speed;              // Tốc độ di chuyển (theo ô)
    int droppedGold;        // Tiền rơi ra khi bị hạ

public:
    Enemy(int _health = 0, int _x = 0, int _y = 0, int _speed = 0, int _droppedGold = 0) {
        health = _health;
        position.x = _x;
        position.y = _y;
        speed = _speed;
        droppedGold = _droppedGold;
    }
    // Phương thức di chuyển kẻ địch
    void move() {
        position.y -= speed;    // Cập nhật tọa độ y
        cout << "Enemy moved to position: (" << position.x << ", " << position.y << ")" << endl;
    }

    // Phương thức nhận sát thương
    void takeDamage(int damage) {
        health -= damage;       // Giảm máu
        if (health < 0) {
            health = 0;         // Đảm bảo máu không âm
        }
        cout << "Enemy took damage: " << damage << ", remaining health: " << health << endl;
    }

    // Getter cho droppedGold
    int getDroppedGold() {
        return droppedGold;
    }

    // Getter cho health
    int getHealth() {
        return health;
    }
};

int main() {
    Enemy enemy(100, 1, 10, 1, 100);    // Tạo một kẻ địch với 100 máu, vị trí (1, 10), tốc độ 1, và tiền rơi 100
    enemy.move();                       // Kẻ địch di chuyển
    enemy.takeDamage(10);               // Kẻ địch nhận sát thương
    cout << "Gold dropped: " << enemy.getDroppedGold() << endl;
    system("pause");
    return 0;
}