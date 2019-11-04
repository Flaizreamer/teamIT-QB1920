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

const int maxN = 101;
const LL oo = 1e17 + 11;

int M,N;
int A[maxN][maxN];
bool C[maxN][maxN];
string s;

void dfs(int i,int j){ // 
    if(i <= 0 || i > M || j <= 0 || j > N || A[i][j] == 0 || C[i][j]) return ;
    // nếu là ô không ở trong bảng hoặc không phải ô chưa số 1 hoặc là ô ĐÃ DUYỆT
    C[i][j] = 1;
    dfs(i + 1,j); // duyệt tất cả các cạnh (các đỉnh kề)
    dfs(i,j + 1);
    dfs(i - 1,j);
    dfs(i,j - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);

    cin >> M >> N; // hàng cột

    FOR(i,1,M){
        cin >> s; // nhập xâu độ dài tương ứng với hàng i
        REP(j,0,N){ // duyệt từ 0 -> N - 1
            A[i][j + 1] = s[j] == '#' ? 1 : 0;
            // cú pháp s[j] == '#' ? 1 : 0 có ý nghĩa : nếu s[j] == '#' thì trả về 1 còn ngược lại trả về 0
        }
    }
    
    int res = 0;
    FOR(i,1,M) FOR(j,1,N) if(A[i][j] == 1 && !C[i][j]){ // nếu chưa duyệt
        ++res;
        dfs(i,j); //
    }

    cout << res;
    
    return 0;
}