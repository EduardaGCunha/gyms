#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int INF = 1e15;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    // v, custo
    queue<pair<int, int>> pq;
    vector<vector<int>> dist(n+1, vector<int>(k + 1, INF));
    
    dist[1][0] = 0;
    pq.push({1, 0});
    
    while(!pq.empty()){
        auto [v, custo] = pq.front(); pq.pop();

        for(auto [u, w] : graph[v]){
            int nxt = custo + w;
            if(nxt <= k && dist[u][nxt] == INF){
                dist[u][nxt] = dist[v][custo] + 1;
                pq.push({u, nxt});
            }
        }
    }

    int ans = INF;
    for(int i = 0; i <= k; i++){
        ans = min(ans, dist[n][i]);
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}