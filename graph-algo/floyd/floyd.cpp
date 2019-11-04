#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)
#define FORD(i,r,l) for(int i = r; i >= l; --i)
#define REPD(i,r,l) for(int i = r; i > l; --i)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second

const int maxN = 1e2 + 1;
const int oo = 1e9 + 1;

int N,M,K;
vector <pi> e[maxN]; // e[u] chứa các cặp (v,c) với ý nghĩa có đường đi u <-> v với trọng số c
// Trong hầu hết trường hợp sử dụng thuật toán floyd, vì độ phức tạp là N^3 nên số đỉnh phải khá nhỏ ~ 400^3
// => Không cần sử dụng vector mà có thể sử dụng luôn ma trận trọng số cạnh
int F[maxN][maxN],T[maxN][maxN];
/* F[i][j] : đường đi ngắn nhất từ i -> j
T[i][j] : đỉnh kế tiếp SAU i trên đường đi ngắn nhất từ i -> j */

void floyd(){
    FOR(i,1,N) FOR(j,1,N){
        F[i][j] = oo; // oo phải > đường đi lớn nhất có thể = (N - 1) * trọng số lớn nhất của mỗi cạnh
        T[i][j] = j;
    }
    FOR(i,1,N){
        REP(j,0,e[i].size()){
            int k = e[i][j].fi; // = e[i][j].first vì đã define ở trên
            int cost = e[i][j].se; // = e[i][j].second
            F[i][k] = F[k][i] = min(F[i][k],cost); // Khởi tạo F[i][j] là trọng số của đường đi từ i -> j
        }
        F[i][i] = 0;
    }

    //
    FOR(k,1,N)
    FOR(i,1,N)
    FOR(j,1,N)
        if(F[i][j] > F[i][k] + F[k][j]){ // thử đi từ i -> k -> j
            F[i][j] = F[j][i] = F[i][k] + F[k][j];
            T[i][j] = T[i][k]; // 
            T[j][i] = T[j][k]; // Khi cập nhật mảng T nhất đỉnh phải cập nhật 2 chiều
        }

}

void find(int s,int v,int total = 1){ // total = số lượng đỉnh từ v trở về sau (tính cả v)
    if(v == s){
        cout << total << " ";
    }else{
        int u = T[s][v]; // đỉnh liền trước v trên đường đi từ s -> v
        if(u == v) find(s,s,total + 1); // in ra số lượng đỉnh
        else find(s,u,total + 1); // tìm đường đi từ s -> đỉnh ngay trước v
    }
    cout << v << " ";
}
void query(){
    int t,x,y;
    cin >> t >> x >> y;
    if(t == 0){
        cout << F[x][y] << endl;
    }else{
        find(x,y); // Hàm truy vết đệ quy tìm đường đi ngắn nhất từ x -> y
        // có thể dùng vòng lặp while để truy vết thay vì dùng đệ quy
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    cin >> N >> M >> K; // số đỉnh / số cạnh / số truy vấn

    FOR(i,1,M){
        int u,v,c;
        cin >> u >> v >> c;
        e[u].push_back(mp(v,c));
        e[v].push_back(mp(u,c));
    }

    floyd();

    FOR(i,1,K) query();

    return 0;
}