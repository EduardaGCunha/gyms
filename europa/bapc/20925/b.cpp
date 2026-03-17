#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

using namespace std;

const int INF = 1e9;

signed main(){
    fastio;
    vector<string> arr(6);
    for(int i = 0; i < 6; i++){
        cin >> arr[i];
    }


    vector<vector<int>> dp(6, vector<int>(16, INF));
    for(int j = 0; j < 6; j++){
        if(j == 0) dp[j][0] = 0;
        else if(j == 5) dp[j][0] = 2;
        else dp[j][0] = 1;
    }

    // for(int j = 0; j < 6; j++){
    //     for(int i = 0; i < 16; i++){
    //         if(dp[j][i] == INF) cout << -1 << " ";
    //         else cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i < 16; i++){
        for(int j = 0; j < 6; j++){
            int val = 0;
            if(j >= 1 && j <= 4) val = 1;
            else if(j == 5) val = 2;
            for(int k = 0; k < 6; k++){
                char cur = (arr[j][i] == 'Q' ? 'Q' : arr[j][i]);
                char prev = (arr[k][i-1] == 'Q' ? 'U' : arr[k][i-1]);
                if (cur >= prev) {
                    dp[j][i] = min(dp[j][i], dp[k][i-1] + val);
                }
            }
        }
    }

    int ans = INF;
    for(int j = 0; j < 6; j++){
        ans = min(ans, dp[j][15]);
    }
    if(ans == INF) cout << "impossible\n";
    else cout << ans << endl;
}
