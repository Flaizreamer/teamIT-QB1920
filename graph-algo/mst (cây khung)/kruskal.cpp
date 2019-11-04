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

const int maxM = 2e5 + 11;
const LL oo = 1e17 + 11;

struct Edge{
    int u,v,c;
};

int tcases = 1;
int N,M;
Edge e[maxM];
int G[maxM];

int find(int u){
    int z = u;
    while(z != G[z]) z = G[z];
    G[u] = z; // update lại để lần sau tìm nhanh hơn
    return z;
}
void Join(int u,int v){
    int g1 = find(u);
    int g2 = find(v);
    G[g1] = g2; // gán ngẫu nhiên nên xác suất độ cao cây giảm sẽ khá lớn => giảm thiểu số lần tìm cha ở hàm find
}
bool cmp(Edge X,Edge Y){
    return X.c < Y.c; // nếu true thì X sẽ ở trước Y trong mảng, nếu false thì Y ở trước X
}
void testcase(){
    cin >> N >> M;
    FOR(i,1,M){
        cin >> e[i].u >> e[i].v >> e[i].c;
    }
    sort(e + 1,e + 1 + M,cmp); // sort tăng dần sử dụng hàm so sánh
    // để sort trong đoạn [l,r] thì gọi câu lệnh => sort(Arr + l,Arr + r + 1) với Arr là mảng cần sort
    
    int res = 0;

    FOR(i,1,N) G[i] = i;
    FOR(i,1,M){
        int u = e[i].u;
        int v = e[i].v;
        if(find(u) != find(v)){
            Join(u,v);
            res += e[i].c;
        }
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