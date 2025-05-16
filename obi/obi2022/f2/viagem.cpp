#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e4+7;
const int INF = 1e18;

vector<tuple<int, int, int>> graph[MAXN];
int dist[MAXN][207];

signed main(){
    int V, n, m; 
    cin >> V >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, t, p; 
        cin >> a >> b >> t >> p;
        a--, b--;
        graph[a].push_back({b, t, p});
        graph[b].push_back({a, t, p});
    }

    for(int i = 0; i < n; i++) 
        fill(dist[i], dist[i] + 207, INF);
    
    int a, b; 
    cin >> a >> b;
    a--, b--;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, a, 0});
    dist[a][0] = 0;

    while(!pq.empty()){
        auto [time, v, cost] = pq.top(); pq.pop();

        if (time > dist[v][cost]) continue;

        for(auto [u, t, p] : graph[v]){
            int new_cost = cost + p;
            int new_time = time + t;

            if(new_cost <= V && new_time < dist[u][new_cost]){
                dist[u][new_cost] = new_time;
                pq.push({new_time, u, new_cost});
            }
        }
    }

    int answer = INF;
    for(int c = 0; c <= V; c++) 
        answer = min(answer, dist[b][c]);

    if(answer == INF) 
        cout << -1 << endl;
    else 
        cout << answer << endl;
}
