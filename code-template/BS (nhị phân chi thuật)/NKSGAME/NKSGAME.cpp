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

const int maxN = 2e5 + 11;
const int oo = 2e9 + 123;

int tcases = 1;
int N;
int A[maxN],B[maxN];

int findLower(int x){ // tìm số lớn nhất <= x trong mảng B
    int l = 1,r = N;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(B[mid] <= x) l = mid;
        else r = mid - 1;
    }
    for(int i = r; i >= l; --i) if(B[i] <= x) return B[i];
    return B[1];
}
int findUpper(int x){ // tìm số nhỏ nhất >= x
    int l = 1,r = N;
    while(l + 1 < r){
        int mid = (l + r)/2;
        if(B[mid] >= x) r = mid;
        else l = mid + 1;
    }
    for(int i = l; i <= r; ++i) if(B[i] >= x) return B[i];
    return B[1];
}
void testcase(){
    cin >> N;
    FOR(i,1,N) cin >> A[i];
    FOR(i,1,N) cin >> B[i];

    sort(B + 1,B + 1 + N);
    
    int res = oo;

    FOR(i,1,N){
        int a = findUpper(-A[i]);
        res = min(res,abs(A[i] + a));
        int b = findLower(-A[i]);
        res = min(res,abs(A[i] + b));
    }
    
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);

    FOR(i,1,tcases) testcase();

    return 0;
}