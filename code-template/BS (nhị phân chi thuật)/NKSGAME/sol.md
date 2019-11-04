### Thuật toán bài NKSGAME
+ Sort mảng B tăng dần
+ Xét với mỗi phần tử x trong A[], ta muốn tìm phần tử y trong B[] để abs(x + y) là nhỏ nhất, tức là x + y gần 0 nhất có thể <=> y gần -x nhất có thể  
=> Ta dùng thuật chặt nhị phân tìm trong B 2 số : số y nhỏ nhất >= -x và số y lớn nhất <= -x
+ Kết quả sẽ là min của abs(x + y)