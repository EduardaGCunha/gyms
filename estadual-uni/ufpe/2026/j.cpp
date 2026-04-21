#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n, m; cin >> n >> m;
    cout << (n/(gcd(n, m))) << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}