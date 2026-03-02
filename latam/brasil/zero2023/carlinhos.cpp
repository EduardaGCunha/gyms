#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e6;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res *= a;
        a *= a;
        b/=2;
    }
    return res;
}

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    int maximo = fastexpo(2*n, 2);
    int mod = (2*n+1);
    for(int i = 2*n; i >= 1; i--){
        int v = fastexpo(i, 2);
        if(v == m) continue;
        if((v - m)%mod == 0){
            cout << v << endl;
            break;
        }
    }

}
