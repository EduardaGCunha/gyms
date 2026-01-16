#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e9;
const int MAXN = 1e6+7;
int pref[MAXN];

signed main(){
	fastio;
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ex(n+1); 
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        ex[i] = {a, b};
        pref[a]++;
    } 

    vector<tuple<int, int, int>> pass;
    for(int i = 0; i < k; i++){
        int p, d, c; cin >> p >> d >> c;
        pass.push_back({p, d, c});
    }


    for(int i = 1; i < MAXN; i++){
        pref[i] += pref[i-1];
    }
    
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + ex[i].second;
        for(auto [p, d, c] : pass){
            int limite1 = max(1LL, i - d + 1);

            int v = ex[i].first - p;
            int limite2 = 1;
            if(v >= 0){
                limite2 += pref[v];
            }
            //int limite2 = pref[max(ex[i].first-p, 0LL)]+1;
            dp[i] = min(dp[i], dp[max(limite1, limite2)-1] + c);
        }
    }

    cout << dp[n] << endl;
}