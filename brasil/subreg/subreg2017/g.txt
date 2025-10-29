#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int MAXN = 1e5;
const int T = 51;
const int MOD = 1e9+7;
int dp[T][MAXN];

signed main(){
    fastio;
    int t, n, m; cin >> t >> n >> m;

    for(int i = 1; i <= t; i++){
        for(int j = n; j <= m; j++){
            if(i == 1) dp[i][j] = 1;
            else{
                if(j - 1 >= n) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%MOD;
                if(j + 1 <= m)  dp[i][j] = (dp[i][j] + dp[i-1][j+1])%MOD;
            }
        }
    }

    int ans = 0;
    for(int i = n; i<= m; i++){
        ans = (ans + dp[t][i])%MOD;
    }
    cout << ans << endl;
    
}