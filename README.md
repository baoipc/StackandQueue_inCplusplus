# Danh sách liên kết
## I.Giới thiệu
## _**Danh sách liên kết ngầm**_ (mảng)
- Cấu trúc dữ liệu gồm giá trị của bản thân 
- Mối liên hệ giữa các phần tử a<sub>i</sub> là phần tử thứ i và kề phần tử a<sub>i+1</sub>
- Lưu trữ các phần tử của mảng trong bộ nhớ
>Công thức xác định địa chỉ phần tử thứ i:
address(i) = address(1)+(i-1)*sizeof(T)

###### Ưu điểm
- Truy xuất trực tiếp, nhanh chóng
- Kiểu dữ liệu quen thuộc, dễ sử dụng
###### Nhược điểm
- Sử dụng bộ nhớ kém hiệu quả, không linh hoạt do kích thước phải được xác định trước và cố định 
- Thao tác thêm hoặc xóa phần tử không hiệu quả
## _**Danh sách liên kết tường minh**_
- Cấu trúc dữ liệu gồm giá trị bản thân và địa chỉ của phần tử kế trong danh sách
- Mỗi phần tử là một biến động
###### Ưu điểm
- Sử dụng hiệu quả bộ nhớ
- Linh động về số lượng phần tử
### Các loại danh sách liên kết
- Danh sách liên kết đơn: mỗi phần tử liên kết với phần tử đứng sau nó trong danh sách
- Danh sách liên kết đôi: mỗi phần tử liên kết với phần tử đứng trước và phần tử đứng sau trong danh sách
- Danh sách liên kết vòng: Phần tử cuối cùng của danh sách liên kết với phần tử ở dầu danh sách, có 2 loại:
    + Danh sách liên kết đơn vòng
    + Danh sách liên kết đôi vòng
# II.Cụ thể về danh sách liên kết
### Các thao tác 
###### Tạo danh sách
Dùng class tạo ít nhất 2 trường trong public(giả sử là trường "value" và trường "next"):
    - value: lưu trữ giá trị của phần tử đó
    - <tên_class>* next: trường để tạo liên kết với nút kế tiếp( hoặc nút phía sau đôi với danh sách liên kết đôi)
###### Tạo một phần tử
Do danh sách liên kết, mỗi phần tử là một con trỏ nên câu lệnh khai báo sẽ khác.
> Câu lệnh: <tên_class>* <tên_biến> = NULL
Ví dụ:
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;
    first->value = 1;
    first->next = second; 
    ...

###### Duyệt danh sách
Khi nào sự trỏ tới của phần tử = null (tức là không còn phần tử nào) thì ta dừng

###### Tìm một phần tử có giá trị cho trước
- Truyền vào hàm bao gồm tham số trỏ ở đầu danh sách và giá trị k cần tìm. 
- Cần kiểm tra tham số trỏ ở đầu danh sách để tránh truyền vào danh sách rỗng
- Tiến hành duyệt từ đầu danh sách 

###### Thêm một phần tử có giá trị cho trước vào danh sách
- Truyền vào hàm bao gồm tham số trỏ ở đầu danh sách và giá trị k cần chèn vào. 
- Cần kiểm tra tham số trỏ ở đầu danh sách để tránh truyền vào danh sách rỗng
- Chia làm 3 loại: chèn đầu danh sách, chèn ở vị trí bất kì, chèn ở vị cuối danh sách 

###### Hủy một phần tử trong danh sách
- Truyền vào hàm bao gồm tham số trỏ ở đầu danh sách và giá trị k cần tìm. 
- Cần kiểm tra tham số trỏ ở đầu danh sách để tránh truyền vào danh sách rỗng
- Chia làm 2 loại: Hủy một phần tử dựa vào giá trị hoặc dựa vào vị trí

###### Tìm kiếm
- Phương pháp: tìm kiếm tuyến tính. Thời gian: độ dài danh sách liên kết
- Tìm kiếm phụ thuộc value hoặc index 
###### Sắp xếp danh sách liên kết đơn
###### Hủy danh sách


_**Cập nhật lần cuối: 7/12/2021**_