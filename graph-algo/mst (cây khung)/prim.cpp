#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

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

const int maxN = 2e5 + 11;
const int oo = 1e9 + 123;

int tcases = 1;
int N,M;
vector <pi> e[maxN];
int D[maxN];

struct cmp{
    bool operator ()(pi X,pi Y){
        return X.fi > Y.fi; // true thì X sẽ xuống dưới và Y sẽ lên trên top, ngược lại với hàm sort
        // => với cách viết hàm so sánh như thế này, heap chúng ta sẽ là heap min vì những phần tử nhỏ hơn sẽ đi lên trên
        // Hàm so sánh của priority_queue phải là 1 struct khác với sort chỉ cần 1 hàm là được
    }
};

priority_queue <pi,vector <pi>,cmp> heap; // heap
// first là khoảng cách ngắn nhất từ cây khung tới đỉnh second

void updateMST(int u){ // cập nhật khoảng cách từ cây khủng tới những đỉnh chưa thuộc cây khung
    REP(i,0,e[u].size()){
        int v = e[u][i].fi;
        int cost = e[u][i].se;
        if(cost < D[v]){
            D[v] = cost;
            heap.push(mp(cost,v)); // update khoảng cách ngắn nhất từ cây khung tới đỉnh v
        }
    }
}
void clearHeap(){
    // với bài có nhiều testcase và sử dụng heap nhiều lần thì phải xoá heap 
    // while(!heap.empty()) heap.pop();
}
void testcase(){
    cin >> N >> M;
    FOR(i,1,M){
        int u,v,c;
        cin >> u >> v >> c;
        e[u].push_back(mp(v,c));
        e[v].push_back(mp(u,c));
    }
    //
    clearHeap();

    FOR(i,1,N) D[i] = oo; // khoảng cách gần nhất từ cây khung hiện tại tới đỉnh i
    D[1] = -1; // ban đầu cây khung chỉ gồm đỉnh 1
    
    int res = 0;
    updateMST(1);
    while(!heap.empty()){
        pi PP = heap.top(); // lấy phần tử ở đỉnh của heap
        heap.pop(); // xoá phần tử ở đỉnh
        int cost = PP.first;
        int u = PP.second;
        //
        if(cost != D[u]) continue; // nếu khoảng cách này chưa được cập nhật thì loại
        // Mỗi lần cập nhật khoảng cách khi thêm đỉnh mới, cạnh nhỏ hơn sẽ "nổi" lên trên
        // Nhưng sau khi ta thêm hết N đỉnh thì vẫn còn những cạnh lớn chưa được pop ra
        // Khi đó ta có thể kiểm tra số đỉnh đã được thêm vào cây khung = N hay không để thoát ra
        D[u] = -1;
        res += cost; // thêm đỉnh u vào cây khung
        updateMST(u);
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    FOR(i,1,tcases) testcase();

    return 0;
}