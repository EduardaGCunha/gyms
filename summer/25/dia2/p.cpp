#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 1e3+7;
int grid[MAXN][MAXN], visited[MAXN][MAXN];
int ans = 0;

int d1[] = {1, 0, -1, 0};
int d2[] = {0, 1, 0, -1};
int n, m;

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    int cnt = 0;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        cnt += grid[x][y];
        for(int i = 0; i < 4; i++){
            int dx = x + d1[i];
            int dy = y + d2[i];
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= m) continue;
            if(grid[dx][dy] && !visited[dx][dy]){
                visited[dx][dy] = 1;
                q.push({dx, dy});
            }
        }
    }
    ans = max(ans, cnt);
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                visited[i][j] = 0;
                cin >> grid[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !visited[i][j]) bfs(i, j);
            }
        }

        cout << ans << endl;
    }
}