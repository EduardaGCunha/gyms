#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e3+7;
const int MAXM = 1e6+7;
char grid[MAXN][MAXN];
int visited[MAXN][MAXN], comp[MAXN][MAXN];
int val[MAXM];
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
int n, m, c = 0;

void dfs(int x, int y){
    int cnt = 0;
    //conta os q tem em volta primeiro
    visited[x][y] = 1;
    comp[x][y] = c;
    for(int i = 0; i < 4; i++){
        int dx = d1[i] + x;
        int dy = d2[i] + y;
        if(dx < 0 || dx >= n) continue;
        if(dy < 0 || dy >= m) continue;
        if(grid[dx][dy] == '*') {
            cnt++;
        }
    } 
    //cout << endl;
    //cout << x+1 << " " << y+1 << " " << cnt << endl;

    val[c] += cnt;
    for(int i = 0; i < 4; i++){
        int dx = d1[i] + x;
        int dy = d2[i] + y;
        if(dx < 0 || dx >= n) continue;
        if(dy < 0 || dy >= m) continue;
        if(grid[dx][dy] != '*' &&  !visited[dx][dy]){
            dfs(dx, dy);
        }
    }
}

int main(){
    fastio;
    int q; cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != '*' && !visited[i][j]){
                c++;
                dfs(i, j);
            }
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        cout << val[comp[a][b]] << endl;
    }
}