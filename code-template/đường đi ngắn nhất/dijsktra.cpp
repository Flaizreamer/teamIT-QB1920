#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int maxN = 123456;
const int oo = 1e9 + 123;

int N,M,K;
int D[maxN],Trace[maxN];
vector <pi> e[maxN];

struct cmp{
    bool operator ()(pi X,pi Y){
        return X.se > Y.se; // phần tử có second nhỏ hơn sẽ ở trên, phần tử có second nhỏ nhất sẽ ở đỉnh của heap
    }
};

priority_queue <pi,vector<pi>,cmp> heap;

void dijkstra(int s,int t){
    FOR(i,1,N) D[i] = oo;
    D[s] = 0;
    while(!heap.empty()) heap.pop(); // pop đến khi heap rỗng / clear heap
    heap.push(mp(s,0));
    while(heap.size()){
        int u = heap.top().fi;
        int cost = heap.top().se;
        heap.pop();
        if(cost != D[u]) continue;
        REP(i,0,e[u].size()){
            int v = e[u][i].fi;
            int newcost = e[u][i].se + cost;
            if(newcost < D[v]){
                D[v] = newcost;
                Trace[v] = u;
                heap.push(mp(v,D[v]));
            }
        }
    }
}
void find(int u,int s,int cnt = 0){
    if(u == s){
        cout << cnt + 1 << " " << u << " ";
    }else{
        find(Trace[u],s,cnt + 1);
        cout << u << " ";
    }
}
void answerQuery(){
    int z,s,t;
    cin >> z >> s >> t;
    dijkstra(s,t);
    if(z == 0) cout << D[t] << endl;
    else{
        find(t,s);
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //
    cin >> N >> M >> K;
    FOR(i,1,M){
        int u,v,c;
        cin >> u >> v >> c;
        e[u].pb(mp(v,c));
        e[v].pb(mp(u,c));
    }
    FOR(i,1,K) answerQuery();
    return 0;
}