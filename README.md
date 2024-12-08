
# Thiết kế game tower defense

Đây là chương trình console-based về game thủ thành sử dụng ngôn ngữ C++ áp dụng tính đa hình và kế thừa.



# Classes
### Enemy  
Enemy: lớp cha đại diện cho quái trong game.  
FastEnemy: Lớp con của enemy, đặc điểm nổi bật là khoảng cách di chuyển được x2.  
TankEnemy: Lớp con của enemy, đặc điểm nổi bật là chịu được sát thương tốt hơn.
### Tower
Tower: lớp cha đại diện cho tháp trong game.  
Cannon Tower: lớp con của tower, đặc điểm nổi bật là sát thương diện rộng.  
Power Tower: lớp con của tower, đặc điểm nổi bật là sát thương lớn hơn.
### Player
Player: lớp này đại diện cho người chơi, lưu trữ các thông tin liên quan như vàng, số mạng.
### Game
Game: lớp này đại diện cho toàn bộ game, dùng để quản lý các thông tin như Player, Tower, Enemy, map, difficulty,...
#  Giới Thiệu Game
- Game sẽ có 3 độ khó, dựa vào đó số lượng enemy sẽ được tạo ra tương ứng là 3,6,9.
- Bản đồ của game sẽ cố định là 3x10, với hai hàng 0,2 là nơi các Tower được đặt, hàng giữa là nơi Enemy di chuyển từ trái qua.

|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | X |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 |   |   |   |   |   |   |   |   |   |   |  
| 1 |   |   |   |   |   |   |   |   |   |   |   
| 2 |   |   |   |   |   |   |   |   |   |   |  
| Y |
- Khi đặt tháp C,P sẽ đại diện cho CannonTower và PowerTower, còn F,T là cho FastEnemy và TankEnemy 

|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | X |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | C  |   |  P |   |   |   |   |   |   |   |  
| 1 |   |   F|   | T  | F  |   |   |   |   |   |   
| 2 |  C | P  |   |C   |   |   |   |   |   |   |  
| Y |
- Người chơi sẽ thắng khi tiêu diệt toàn bộ quái của độ khó mà mình chọn trong khi số mạng > 0. Ngược lại trò chơi sẽ kết thúc nếu số mạng < 0.

# Cách chạy trên local

Clone dự án về thư mục mong muốn

```bash
  git clone https://github.com/Sanglaga18/PreludeTowerDefense.git
```

Mở thư mục ra

```bash
  cd PreludeTowerDefense
```

Tìm file có đuôi .sin

```bash
  PreludeTowerDefense.sin
```

Mở file đó bằng ide như Visual Studio

```bash
  Open with Visual Studio
```


# Nhóm Prelude
- [@Hientrietman](https://github.com/Hientrietman)
- [@Sanglaga18](https://github.com/Sanglaga18)
- [@Vany856](https://github.com/Vany856)
- [@MinhNhatStudent](https://github.com/MinhNhatStudent)

