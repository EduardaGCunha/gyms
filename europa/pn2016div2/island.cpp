#include <bits/stdc++.h>
using namespace std;

int n, m; 
const int MAXN = 50;
char grid[MAXN][MAXN];
int visited[MAXN][MAXN];

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

int main(){
    cin >> n >> m;
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'L') pos.push_back({i, j});
        }
    }

    int cnt = 0;
    for(auto [k, l]: pos){
        if(!visited[k][l]){
            cnt++;
            queue<pair<int, int>> q;
            q.push({k, l});
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int dx = x + d1[i];
                    int dy = y + d2[i];
                    if(dx < 0 || dx >= n) continue;
                    if(dy < 0 || dy >= m) continue;
                    if(visited[dx][dy]) continue;
                    if(grid[dx][dy] == 'L' || grid[dx][dy] == 'C'){
                        visited[dx][dy] = 1;
                        q.push({dx, dy});
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}