#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 500;
const int INF = 1e8;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];

void bfs(){
    //dist, x, y
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 1;
    while(!pq.empty()){
        auto [d, u, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[u][v] < d) continue;
        int dv = grid[u][v];

        vector<pair<int, int>> conn = {
            {u + dv, v}, {u - dv, v}, {u, v + dv}, {u, v - dv}
        };

        for(auto [x, y] : conn){
            if(x < 0 || x >= n) continue;
            if(y < 0 || y >= m) continue;
            if(dist[x][y] > dist[u][v]+1){
                dist[x][y] = dist[u][v]+1;
                pq.push({-dist[x][y], x, y});
            }
        }
        
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = (s[j]-'0');
            dist[i][j] = INF;
        }
    }

    bfs();
    if(dist[n-1][m-1] == INF) cout << "IMPOSSIBLE\n";
    else cout << dist[n-1][m-1]-1 << endl;
}