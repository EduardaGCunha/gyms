#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int MAXN = 2*(1e5)+9;
vector<pair<int, int>> graph[MAXN];

signed main(){
    fastio;
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--, t--;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }

    vector<int> ans(n, -1);
    ans[s] = 1e18;
    priority_queue<pair<int, int>> pq;
   
    pq.push({ans[s], s});
    while(!pq.empty()){
        auto [cur, v] = pq.top(); pq.pop();
        //cout << cur << " " << v << endl;

        if(cur < ans[v]) continue;

        if(v == t){
            cout << ans[t] << endl;
            return 0;
        }

        for(auto u : graph[v]){
            int cap = min(cur, u.second);
            if(cap > ans[u.first]){
                ans[u.first] = cap;
                pq.push({cap, u.first});
            }
        }
    }

    cout << -1 << endl;
}