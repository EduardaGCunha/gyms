#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MOD = 2026;

void solve(){
    int n; cin >> n;
    vector<int> dp(n+3, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }
    cout << dp[n] << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}