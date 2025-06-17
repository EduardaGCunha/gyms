#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

vector<vector<int>> graph;

//dfs p/ descobrir se consigo alcancar o cara ou nao
int n, m;
int forbid = 0;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

void dfs(int x, int y, vector<vector<int>> &visited){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int dx = x + d1[i];
        int dy = y + d2[i];
        if(dx < 0 || dx >= n) continue;
        if(dy < 0 || dy >= m) continue;
        if(!visited[dx][dy] && !(graph[dx][dy]&forbid)){
            dfs(dx, dy, visited);
        }
    }
}

void solve(int x, int y){
    //valor final e bits q nao podem estar ligados
    int bitmask = 0;
    forbid = 0;
    for(int i = 30; i >= 0; i--){
        forbid |= (1 << i);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dfs(x, y, visited);

        if(!visited[n-1][m-1]){
            bitmask |= (1 << i);
            forbid ^= (1 << i);
        }
    }
    cout << bitmask << " ";
}

signed main(){
    fastio;
    cin >> n >> m;
    graph.resize(n);
    int x, y; cin >> x >> y;
    for(int i = 0; i < n; i++){
        graph[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    solve(0, 0);
    x--, y--;
    solve(x, y);
    cout << endl;

}