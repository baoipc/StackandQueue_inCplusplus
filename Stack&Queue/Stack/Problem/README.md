# Bài toán về Stack

## Chuyển biểu thức trung tố về biểu thức hậu tố

### Biểu thức hậu tố

> Được biểu diễn bằng cách đặt các toán tử sẽ được đặt sau các toán hạng

- Nếu là toán hạng cho ra biểu thức

- Nếu là dấu mở ngoặc "(": cho vào Stack

- Nếu là dấu đóng ngoặc ")": lấy các phần tử trong Stack đang chứa ra cho đến khi gặp dấu ngoặc mở "("

- Nếu là toán tử:

  - Chừng nào ở đỉnh stack là toán tử và toán tử đó có độ ưu tiên **lớn hơn hoặc bằng** toán tử hiện tại thì lấy toán tử đó ra khỏi stack và cho ra output.

  - Đưa toán tử hiện tại vào stack

### Biểu thức tiền tố

> Được biểu diễn bằng cách đặt toán tử lên trước các toán hạng

## Chuyển một số hệ thập phân sang hệ cơ số khác

### Hệ nhị phân (hệ 2)

Dạng bit: 0 và 1

### Hệ thập lục phân (hệ 16)

Giá trị: 0 1 2 3 4 5 6 7 8 9

Chữ cái: A B C D E F (10 -> 15)

### Hệ bát phân (hệ 8)

Giá trị: 0 1 2 3 4 5 6 7 8

## Tính toán cho biểu thức số học

- Trong khi còn đọc chuỗi đầu vào

  - Nếu giá trị hiện tại:
  
    - Giá trị số: Đẩy vào Stack Value

    - Giá trị số(> 1 chữ số): Đẩy vào Stack contain Value

    - Ngoặc mở: Đẩy nó vào Stack contain Operator

    - Ngoặc đóng:

      - Khi đỉnh của Stack contain Operator không phải là dấu ngoặc mở

        - Lấy ra đỉnh của Stack contain Operator

        - Lấy ra 2 đỉnh của Stack contain Value

        - Thực hiện tính toán với phép tính được lấy ra từ Stack contain Operator và 2 giá trị của Stack contain Value

        - Đưa kết quả mới tính được vào Stack contain Value

      - Xóa đỉnh của Stack contain Operator (lúc này là ngoặc mở)

    - Toán tử:

      - Khi Stack contain Operator không rỗng và đỉnh của Stack contain Operator có độ ưu tiên về phép tính >= toán tử hiện tại

        - Lấy ra đỉnh của Stack contain Operator

        - Lấy ra 2 đỉnh của Stack contain Value

        - Thực hiện tính toán với phép tính được lấy ra từ Stack contain Operator và 2 giá trị của Stack contain Value

        - Đưa kết quả mới tính được vào Stack contain Value

      - Đưa toán tử hiện tại vào Stack contain Operator

  - Khi Stack contain Operator chưa rỗng

    - Lấy ra đỉnh của Stack contain Operator

    - Lấy ra 2 đỉnh của Stack contain Value

    - Thực hiện tính toán với phép tính được lấy ra từ Stack contain Operator và 2 giá trị của Stack contain Value

- Đưa kết quả mới tính được vào Stack contain Value

- Lúc này, Stack contain Operator đã trống và kết quả chính là phần tử còn sót lại trong Stack contain Value

## Bài toán “Tháp Hà Nội”

- Bài toán "Tháp Hà Nội" khi chúng ta có n đĩa, chúng được đặt vào 3 cái tháp. Kết thúc trò chơi khi chuyển toàn bộ số đĩa sang cột 3. Đảm bảo bài toán luôn có nghiệm. Quy tắc

  - Mỗi lần chỉ chuyển 1 đĩa
  
  - Không được để đĩa lớn phái trên đĩa nhỏ

  - Chỉ được di chuyển các đĩa nằm trên cùng của cột

- Cách giải: Dùng đệ quy hoặc Stack. Ở đây, bàn về cách dùng Stack

- Thuật toán

  - Viết các hàm lấy đỉnh của Stack (3 Stack tương tự 3 cột) nếu cột rỗng thì trả về giá trị infinity (do đề bài yêu cầu đĩa nhỏ để trên đĩa lớn)
  
  - Đầu tiên, Cột 1 sẽ chứa n đĩa, số bước cần chuyển hết n đĩa đó là 2^n

  - Khi chưa chạy hết số bước 2^n

    - Nếu bước hiện tại là lẻ, kiểm tra xem đỉnh của 1 trong 3 cột có phải là đĩa 1 không

      - Nếu đĩa 1 ở cột 1 thì di chuyển qua cột 3

      - Nếu đĩa 1 ở cột 2 thì di chuyển qua cột 1

      - Nếu đĩa 1 ở cột 3 thì di chuyển qua cột 2

    - Ngược lại nếu bước hiện tại là chẵn

      - Nếu đĩa 1 ở cột 1, lấy ra đĩa đang ở đỉnh cột 2 và cột 3, và chọn cột có đĩa lớn hơn để chứa cả 2 đĩa

      - Nếu đĩa 1 ở cột 2, lấy ra đĩa đang ở đỉnh cột 1 và cột 3, và chọn cột có đĩa lớn hơn để chứa cả 2 đĩa

      - Nếu đĩa 1 ở cột 3, lấy ra đĩa đang ở đỉnh cột 2 và cột 3, và chọn cột có đĩa lớn hơn để chứa cả 2 đĩa
