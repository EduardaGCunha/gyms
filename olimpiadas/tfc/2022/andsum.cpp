#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int MOD = 1e9+7;
#define int long long

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD; 
        b/=2;
    }
    return res;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << fastexpo(n, k) << endl;
    }
}