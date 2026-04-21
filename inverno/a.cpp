#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n; cin >> n;
    cout << (1 + n)*n/2 << endl;
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}