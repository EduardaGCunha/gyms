#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e6)+7;

signed main(){
    int n; cin >> n;
    int points[n], wait[n];
    int wave[MAXN];
    int mx = 0;
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x >> points[i] >> wait[i];
        wave[x + wait[i]] = 1;
        mp[x+wait[i]].push_back(i);
        mx = max(x+wait[i], mx);
    }
    vector<int> dp(MAXN, 0);
    
    for(int i = 1; i <= mx; i++){
        dp[i] = dp[i-1];
        if(!wave[i]) continue;
        for(auto u : mp[i]){
            dp[i] = max(dp[i], dp[i - wait[u]] + points[u]);
        }
    }

    cout << dp[mx] << endl;
    
}