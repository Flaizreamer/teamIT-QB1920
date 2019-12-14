//FLOYD

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for(int i = l; i <= r; ++i)

const int maxN = 101;
const int oo = 1000000000;

int N,M,K;
int o,s,t;
int T[maxN][maxN],F[maxN][maxN];

vector <int> path; //danh sách các đỉnh trên đường đi ngắn nhất từ s -> t

void findTrace(int u){
	path.push_back(u);
	if(u == t) return ; //reached the last vertex
	findTrace(T[u][t]);
}
void find(){
    cin >> o >> s >> t;
	if(o == 0) cout << F[s][t] << endl;
	else{
		path.clear();
		findTrace(s);
		cout << path.size() << " ";
		for(int i = 0; i < path.size(); ++i) cout << path[i] << " ";
		cout << endl;
	}
}
int main(){
	cin >> N >> M >> K;
    FOR(i,1,N){
        F[i][i] = 0;
        FOR(j,i + 1,N) F[i][j] = F[j][i] = oo; // F[i][j] = đường đi ngắn nhất từ i -> j
        //
        FOR(j,1,N) T[i][j] = j; // T[i][j] : đỉnh tiếp theo SAU i TRÊN đường đi ngắn nhất từ i -> j
    }
	FOR(i,1,M){
		int u,v,c;
		cin >> u >> v >> c;
        F[u][v] = F[v][u] = min(F[u][v],c);
	}
    // FLOYD
    FOR(k,1,N)
        FOR(i,1,N)
        FOR(j,1,N) if(F[i][j] > F[i][k] + F[k][j]){
            F[i][j] = F[i][k] + F[k][j];
            T[i][j] = T[i][k];
            T[j][i] = T[j][k];
        }
    
	//
    FOR(i,1,K) find();
    
	return 0;
}