# Cách cài thuật binary search đơn giản

Thuật BS dùng để tìm kiếm một vị trí trên một mảng có tính tăng/giảm dần (theo một hàm so sánh nhất định nào đó) trong thời gian O(log2(N))

Gọi hàm check(x) là hàm kiểm tra phần tử x sao cho hàm check tăng dần trên mảng A  
Tức là ta sẽ có giá trị của hàm check với mảng A như sau : 0 0 0 ... 0 1 1 1 ... 1  
(Hoặc với trường hợp hàm check giảm dần : 1 ... 1 0 ... 0)

Ở đây ta sẽ xét cách cài với hàm tăng dần, còn hàm giảm dần thì tương tự  
Hàm chặt nhị phân cho phép ta tìm vị trí 1 đầu tiên trên mảng tăng dần (hoặc vị trí 0 cuối cùng trên mảng tăng dần)

### Ta có giải thuật tìm vị trí số 0 lớn nhất như sau :
Gọi [l,r] là đoạn liên tục chứa kết quả ta đang tìm kiếm (tính cả l và r)
Đặt mid = (l + r)/2 (chia nguyên)
+ Nếu check(mid) = 0 thì chắc chắn kết quả cần tìm sẽ ở BÊN PHẢI HOẶC BẰNG mid (vì hàm check tăng dần nên từ mid trở về trước sẽ chỉ chứa số 0) -> Ta đặt l = mid
+ Ngược lại nếu check(mid) = 1 thì chắc chắn kết quả cần tìm sẽ ở TRƯỚC mid -> r = mid - 1
Như vậy ta cứ lặp đến khi thu hẹp khoảng [l,r] nhỏ nhất có thể là được (l = r)

### Trường hợp lặp vô hạn
Khi ta thu nhỏ khoảng [l,r] chỉ còn 2 phần tử (l + 1 = r) thì mid = (l + r)/2 = l
Nếu check(mid) = 0 thì khi đó ta sẽ gán l = mid = l và vòng lặp sẽ chạy mãi mãi
Để tránh trường hợp này thì khi l + 1 >= r ta sẽ dừng vòng lặp và duyệt từ r -> l và kiểm tra tìm vị trí số 0 lớn nhất

### Các trường hợp hàm so sánh giảm dần hoặc tìm vị trí bé nhất
Ở những trường hợp này, thuật toán sẽ tương tự và chỉ cần đổi chiều vòng lặp (l -> r) hoặc đổi chiều gán (l = mid + 1 và r = mid) tuỳ theo mục đích của hàm nhị phân.

### Giả mã :
<pre>
int BS(){ // Tìm vị trí số 0 lớn nhất  
    int l = 1,r = N;  
    while(l + 1 < r){  
        int mid = (l + r)/2;  
        if(check(mid)) r = mid - 1;  
        else l = mid;  
    }  
    for(int i = r; i >= l; --i) if(!check(i)) return i;  
    return 0; // không tìm được kết quả  
}  
</pre>