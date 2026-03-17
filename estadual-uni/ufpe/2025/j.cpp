#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> conn(m);
    for(int i = 0; i < m; i++){
        int tot; cin >> tot;
        for(int j = 0; j < tot; j++){
            int x; cin >> x;
            x--;
            conn[i].push_back(x);
        }
    }

    vector<double> ans(k+1, 0.0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        double prob = 1.0/(double)conn[x].size();
        for(auto u : conn[x]){
            ans[u] += prob;
        }
    }

    for(int i = 0; i < k; i++){
        cout << fixed << setprecision(15) << ans[i] << " ";
    }
    cout << endl;
}

signed main(){
    fastio;
    int t=1;
    while(t--){
        solve();
    }
}