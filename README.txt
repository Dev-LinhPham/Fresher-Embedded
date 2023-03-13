Kiến thức OOP được a Hiếu dạy:
+ Class ? Cách khai báo Ckass
+ Các thành phần của Class
+ Phạm vi truy cập: Pulic và Private
+ Constructor
+ Đặc tính của OOP



- Class cũng là 1 kiểu người dùng định nghĩa. Sử dụng để mô tả đối tượng (Object).
- Trong Class bao gồm dữ liệu/biến (property) và phương thức/hàm (method).
- Phạm vi truy cập Public: Các đối tượng (Object) có thể trỏ tới được các property trong Class để lấy giá trị hoặc gán giá trị cho chúng.
- Phạm vi truy cập Private: Các đối tượng không thể truy cập trực tiếp tới Property mà phải thông qua Method ở Public để lấy hoặc khởi tạo giá trị.
- Constructor là 1 hàm dựng sử dụng để khai báo hoặc khởi tạo giá trị cho Property khi tạo ra 1 Object. Tránh việc phải gọi từng Property để khởi tại giá trị.
- Mặc định trong Class đã được #define Constructor (không tham số), khi mà Class mình tạo không có Constructor thì sẽ mặc định dùng cái #define còn đã được khởi tạo Constructor
thì sẽ loại bỏ #define Constructor.
- 4 đặc tính của OOP:
	+ Tính trừu tượng: Chỉ tập trung vào dữ liệu có liên quan đến đối tượng. Ẩn các chi tiết nền (cơ sở)

	+ Tính đóng gói: Là quá trình đóng gói dữ liệu và phương thức. Ngăn không cho truy cập ngẫu nhiên từ bên ngoài.
			 Không cho phép người SD thay đổi trạng thái nội tại (property) của đối tượng
			 Chỉ có phương thức nội tại làm thay đổi trạng thái nội tại đó.
	
	+ Tính kế thừa: Class có tính thừa hưởng lại tất cả các thuộc tính, phương thức của class mà nó kế thừa.
			Class kế thừa 1 class khác gọi là lớp con (subclass)
			Class được class khác kế thừa gọi là lớp cha (superclass/baseclass)

	+ Tính đa hình: Một phương thức (method) có thể được thể hiện nhiều dạng khác nhau. 

Băn khoăn: Định nghĩa phần trừu tượng khó hiểu và có phần khá giống tính đóng gói.
	   Sự khác nhau giữa 2 đặc tính này.