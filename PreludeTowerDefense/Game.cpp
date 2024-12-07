#include "Game.h"

// Constructor
Game::Game(int initialGold, int initialHealth, int mapLength, int difficulty, int totalEnemiesSpawned)
    : player(initialHealth, initialGold), mapLength(mapLength), difficulty(difficulty), totalEnemiesSpawned(totalEnemiesSpawned){
    initializeMap();
}

// Destructor
Game::~Game() {
    for (Tower* tower : towers) delete tower;
    for (Enemy* enemy : enemies) delete enemy;
}

// Khởi tạo map trống
void Game::initializeMap() {
    map.resize(3, vector<string>(mapLength, " "));
}

// Hiển thị trạng thái trò chơi
void Game::displayStatus() {
    cout << endl << "Player Gold: " << player.getGold() << " | Lives: " << player.getHealth() << endl;
}

// Hiển thị bản đồ
void Game::displayMap() {
    cout << "  ";
    for (int i = 0; i < mapLength; i++) cout << i << " ";
    cout << "X" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i << "|";
        for (int j = 0; j < mapLength; j++) {
            cout << map[i][j] << "|";
        }
        cout << endl;
        cout << string(mapLength * 2 + 1, '-') << endl;
    }
    cout << "Y" << endl << endl;
}

// Thêm tháp
void Game::addTower(Tower* tower, int x, int y) {
    map[y][x] = tower->getType(); // C hoặc P
    towers.push_back(tower);
    displayMap();
    player.setGold(player.getGold() - tower->getCost());
}

// Sinh enemy mới
void Game::spawnEnemy() {
    // Kiểm tra nếu ô (1, 0) trống và số lượng quái hiện tại chưa đạt giới hạn
    if (map[1][0] == " " && totalEnemiesSpawned < difficulty) { // Giới hạn tối đa dựa theo độ khó đã chọn
        Enemy* enemy = nullptr;

        // Sinh ngẫu nhiên loại quái
        if (rand() % 2 == 0) {
            enemy = new FastEnemy(); // FastEnemy
        }
        else {
            enemy = new TankEnemy(); // TankEnemy
        }

        // Thêm quái vào danh sách và bản đồ
        enemies.push_back(enemy);
        map[1][0] = enemy->getType(); // Đặt ký tự đại diện của quái trên bản đồ
        totalEnemiesSpawned++;
        cout << "New enemy spawned at position: (1, 0)" << endl;
        displayMap();
    }
}


// Cập nhật trò chơi
void Game::updateGame() {

    // Di chuyển từng quái vật
    for (size_t i = 0; i < enemies.size(); i++) {
        Enemy* enemy = enemies[i];

        // Kiểm tra xem quái vật có chết không
        if (enemy->enemyIsDead()) {
            player.setGold(player.getGold() + enemy->getDroppedGold());
            Position currentPos = enemy->getPosition();
            map[currentPos.y][currentPos.x] = " "; // Xóa quái trên bản đồ
            delete enemy; // Giải phóng bộ nhớ
            enemies.erase(enemies.begin() + i); // Xóa quái khỏi danh sách
            i--; // Giảm chỉ số lặp lại để không bỏ qua quái tiếp theo
            continue; // Tiếp tục vòng lặp với quái vật tiếp theo
        }

        bool canMove = true;

        // Lấy vị trí hiện tại của quái
        Position currentPos = enemy->getPosition();

        //Xử lý quái chờ khi phía trước có quái khác
        /*int speedEnemy = (enemy->getType() == 'F') ? enemy->getSpeed() * 2 : enemy->getSpeed();  // Tốc độ của quái

        // Lấy tọa độ tiếp theo quái vật sẽ di chuyển tới
        int nextX = currentPos.x + speedEnemy;

        // Kiểm tra nếu có quái vật nào ở ô tiếp theo
        bool occupied = false;
        for (size_t k = 0; k < enemies.size(); k++) {
            if (i != k) { // Không so sánh quái vật với chính nó
                Enemy* otherEnemy = enemies[k];
                Position otherPos = otherEnemy->getPosition();
                if (otherPos.x == nextX && otherPos.y == currentPos.y) {
                    occupied = true; // Nếu có quái vật chặn đường
                    break;
                }
            }
        }

        if (occupied) {
            canMove = false; // Nếu có quái vật chặn, không thể di chuyển
        }*/

        // Nếu quái có thể di chuyển
        if (canMove) {
            // Xóa quái ở vị trí cũ trên bản đồ
            map[currentPos.y][currentPos.x] = " ";

            // Di chuyển quái
            enemy->move();

            // Lấy vị trí mới sau khi di chuyển
            Position newPos = enemy->getPosition();

            
            // Nếu quái vượt ra ngoài bản đồ
            if (newPos.x >= mapLength) {
                player.takeDamage(1);   // Trừ 1 máu của người chơi
                cout << "Enemy escaped! Player took 1 damage. Remaining Lives: " << player.getHealth() << endl;

                // Xóa quái khỏi danh sách
                delete enemy; // Giải phóng bộ nhớ
                enemies.erase(enemies.begin() + i); // Xóa quái khỏi danh sách
                i--; // Giảm chỉ số lặp lại để không bỏ qua quái tiếp theo
            }
            else {
                // Hiện thông báo chờ người chơi nhấn Enter
                cout << "Press Enter to continue...";
                cin.ignore(); // Xóa ký tự thừa nếu cần
                cin.get();    // Chờ người chơi nhấn Enter

                // Cập nhật quái tại vị trí mới trên bản đồ
                map[newPos.y][newPos.x] = enemy->getType();
                displayMap();
            }
        }
    }

    //Spawn quái nếu ô (0,1) trống
    spawnEnemy();

    // Các tháp tấn công
    for (Tower* tower : towers) {
        tower->attack(enemies);  // Truyền vector chứa con trỏ Enemy vào phương thức attack
    }
}

// Kiểm tra vị trí hợp lệ
bool Game::isValidPosition(int x, int y) {
    // Kiểm tra tọa độ hợp lệ
    if (x < 0 || x >= mapLength || (y != 0 && y != 2)) {
        return false; // Không hợp lệ nếu nằm ngoài map hoặc không phải hàng 0, 2
    }

    // Kiểm tra xem vị trí đã có tháp chưa
    if (map[y][x] != " ") { // Nếu không phải là ô trống
        cout << "Position (" << x << ", " << y << ") is already occupied by another tower!" << endl;
        return false;
    }

    return true; // Vị trí hợp lệ
}

// Bắt đầu trò chơi
void Game::play() {
    displayStatus();
    displayMap();

    // Vòng lặp cho phép người chơi mua tháp nếu còn tiền
    string buyMoreTowers = "y";
    while (true) {
        // Yêu cầu người chơi nhập y/n
        cout << "Do you want to buy a tower? (y/n): ";
        cin >> buyMoreTowers;

        // Kiểm tra tính hợp lệ của câu trả lời
        while (buyMoreTowers != "y" && buyMoreTowers != "n") {
            cout << "Invalid input! Please enter 'y' for yes or 'n' for no: ";
            cin >> buyMoreTowers;
        }

        if (buyMoreTowers == "n") {
            break; // Thoát vòng lặp nếu người chơi chọn 'n'
        }

        cout << "1: CannonTower (Cost: 30, Range: 2, Damage: 25)"<< endl;
        cout << "2: PowerTower (Cost: 40, Range: 2, Damage: 20)"<< endl;
        cout << "3: Back" << endl;
        int choice;

        // Yêu cầu người chơi nhập lựa chọn loại tháp
        while (true) {
            cout << "Your choice: ";
            cin >> choice;

            if (choice >= 1 && choice <= 3) {
                break; // Thoát vòng lặp nếu lựa chọn hợp lệ
            }
            else {
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
            }
        }

        if (choice == 3) {
            break; // Người chơi chọn không mua tháp, quay lại vòng chơi
        }

        // Nhập vị trí tháp
        int x, y;
        cout << "Enter tower position (x y): ";
        cin >> x >> y;

        if (isValidPosition(x, y)) {  // Kiểm tra vị trí hợp lệ
            Tower* tower = nullptr;

            // Khởi tạo tháp dựa trên lựa chọn của người chơi
            if (choice == 1) {
                tower = new CannonTower(Position(x, y)); // Tạo CannonTower
            }
            else if (choice == 2) {
                tower = new PowerTower(Position(x, y)); // Tạo PowerTower
            }

            // Kiểm tra xem người chơi có đủ vàng không
            if (tower && player.getGold() >= tower->getCost()) {
                addTower(tower, x, y); // Thêm tháp vào bản đồ
                cout << (choice == 1 ? "CannonTower" : "PowerTower") << " placed at (" << x << ", " << y << ")" << endl;
                cout << "Remaining Gold: " << player.getGold() << endl;
            }
            else {
                cout << "Not enough gold!" << endl;
                delete tower; // Giải phóng bộ nhớ nếu không đủ vàng
            }
        }
        else {
            cout << "Invalid position! Please choose a valid position on the map (row: 0 or 2, column: 0 to " << mapLength - 1 << ")." << endl;
        }
    }

    // Bắt đầu trò chơi
    cout << endl << "Game Started!" << endl;

    for (int turn = 0; turn < 1; turn++) {
        cout << endl << "----------NEW TURN-------- \n" << endl;
        spawnEnemy(); // Sinh ra quái vật mới trong mỗi lượt
        // Các tháp tấn công
        for (Tower* tower : towers) {
            tower->attack(enemies);  // Truyền vector chứa con trỏ Enemy vào phương thức attack
        }
            while (!checkWin() && !checkLose()) { // Lặp đến khi thắng hoặc thua
                updateGame();  // Cập nhật trạng thái trò chơi, di chuyển quái và tấn công
                

                if (checkLose()) {
                    cout << endl;
                    cout << "\033[31m";
                    cout << " *****       *     *       * *****      *****  *       * ***** *****   " << endl;
                    cout << "*     *     * *    * *   * * *         *     *  *     *  *     *    *  " << endl;
                    cout << "*         *******  *   *   * ***       *     *   *   *   ***   *****   " << endl;
                    cout << "*    ***  *     *  *       * *         *     *    * *    *     *  *    " << endl;
                    cout << " *****   *       * *       * *****      *****      *     ***** *    *  " << endl;
                    cout << "\033[0m";
                    cout << endl;
                    displayMap();
                    displayStatus();
                    return;
                }

                if (checkWin()) {
                    cout << endl;
                    cout << "\033[33m";
                    cout << "*       *  *****  *     *     *           * ***** *   * " << endl;
                    cout << "  *   *   *     * *     *      *         *    *   **  * " << endl;
                    cout << "    *     *     * *     *       *   *   *     *   * * * " << endl;
                    cout << "    *     *     * *     *        * * * *      *   *  ** " << endl;
                    cout << "    *      *****   *****          *   *     ***** *   * " << endl;
                    cout << "\033[0m";
                    cout << endl;
                    displayMap();
                    displayStatus();
                    return;
                }
            }
    }

    setTotalEnemiesSpawned(0);
}

bool Game::checkWin() {
    // Thắng khi danh sách quái rỗng và người chơi còn máu
    return enemies.empty() && player.getHealth() > 0;
}

bool Game::checkLose() {
    // Thua khi máu người chơi bằng hoặc nhỏ hơn 0
    return player.getHealth() <= 0;
}

// Getter cho totalEnemiesSpawned
int Game::getTotalEnemiesSpawned() const {
    return totalEnemiesSpawned;
}

// Setter cho totalEnemiesSpawned
void Game::setTotalEnemiesSpawned(int count) {
    totalEnemiesSpawned = count;
}


