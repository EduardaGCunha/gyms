#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


const int INF = 1e18;
const int MAXN = 11;
int grid[MAXN][MAXN];
int dp[(1<<MAXN)][MAXN];


void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < (1<<n); i++){
        for(int j = 0; j < n; j++) dp[i][j] = INF;
    }

    int tot = (1<<n);
    dp[1][0] = 0;
    //p cada ponto inicial
    for(int mask = 0; mask < tot; mask++){
        for(int i = 0; i < n; i++){
            if(dp[mask][i] == INF) continue;
            for(int j = 0; j < n; j++){
                if(mask&(1<<j)) continue;
                int nm = mask | (1<<j);
                dp[nm][j] = min(dp[mask][i] + grid[i][j], dp[nm][j]);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, dp[tot-1][i] + grid[i][0]);
    }
    cout << ans << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}