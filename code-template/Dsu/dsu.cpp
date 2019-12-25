#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

const int N = 1e5 + 123;

int n,m,p[N],res = 0;
pair<int,pair<int,int> > e[N];

int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
void join(int x,int y){
    p[find(x)] = find(y);
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> e[i].se.fi >> e[i].se.se >> e[i].fi;
    }
    sort(e + 1,e + 1 + m);
    for(int i = 1; i <= n; ++i) p[i] = i;
    for(int i = 1; i <= m; ++i){
        if(find(e[i].se.fi) != find(e[i].se.se)){
            join(e[i].se.fi,e[i].se.se);
            res += e[i].fi;
        }
    }

    cout << res;
    return 0;
}