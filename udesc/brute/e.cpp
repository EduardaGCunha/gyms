#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int INF = 1e8;
const int MAXK = 11;
const int MAXN = 2 * (1e5) + 7;
int dist[MAXN][MAXK];
int tipo[MAXN];
vector<int> graph[MAXN];

signed main(){
    fastio;
    int n, m, k; cin >> n >> m >> k;

    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXK; j++) dist[i][j] = INF;
    }
    
    for (int i = 0; i < n; i++) cin >> tipo[i];
    
    for (int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});
    
    while(!pq.empty()){
        auto [d, v, cur] = pq.top();
        pq.pop();
        if(dist[v][cur] < d) continue;
        
        for(auto u : graph[v]){
            int nw = (tipo[u] != tipo[v]) ? 1 : 0;
            if(cur + nw <= k && dist[u][cur + nw] > d + 1){
                dist[u][cur + nw] = d + 1;
                pq.push({d + 1, u, cur + nw});
            }
        }
    }
    
    int ans = INF;
    for (int i = 0; i <= k; i++){
        ans = min(ans, dist[n-1][i]);
    }
    

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
