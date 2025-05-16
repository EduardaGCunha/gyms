#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)


const int MAXN = 50;
char graph[MAXN][MAXN];
int visited[MAXN][MAXN];
int n, m;

int d1[] = {1, 0, -1, 0};
int d2[] = {0, 1, 0, -1};

void dfs(int i, int j){
    visited[i][j] = 1;
    for(int x = 0; x < 4; x++){
        int dx = d1[x] + i;
        int dy = d2[x] + j;
        if(dx < 0 || dx >= n) continue;
        if(dy < 0 || dy >= m) continue;
        if(graph[dx][dy] != 'W' && !visited[dx][dy]){
            dfs(dx, dy);
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 'L' && !visited[i][j]){
                c++;
                dfs(i, j);
            }
        }
    }
    cout << c << endl;
}