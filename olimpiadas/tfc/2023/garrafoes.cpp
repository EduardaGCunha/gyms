#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    int g, m; cin >> g >> m;
    vector<int> coins; 
    coins.push_back(1);
    for(int i = 2; i <= sqrt(g); i++){
        int tot = i*(i+1)*(2*i+1)/6;
        coins.push_back(tot);
    }

    if(m == 1){
        vector<int> dp(g+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= g; i++){
            for(auto u : coins){
                if(i - u >= 0) dp[i] = (dp[i] + dp[i-u])%MOD;
            }
        }

        cout << dp[g] << endl;
    }else{
        vector<int> dpmin(g+1, 1e18);
        vector<int> dpcnt(g+1, 0);
        dpcnt[0] = 1;
        dpmin[0] = 0;
        for(int i = 1; i <= g; i++){
            for(auto u : coins){
                if(i - u >= 0){
                    int dif = dpmin[i-u] + 1;
                    if(dif < dpmin[i]){
                        dpmin[i] = dif;
                        dpcnt[i] = dpcnt[i-u];
                    }else if(dif == dpmin[i]){
                        dpcnt[i] = (dpcnt[i] + dpcnt[i-u])%MOD;
                    }
                }
            }
        }

        cout << dpcnt[g]%MOD << endl;
    }
}