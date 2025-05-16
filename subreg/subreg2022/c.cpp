#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAXN = 2*1000 + 5;
int n;
int visited[MAXN][MAXN], wall[MAXN][MAXN];
int ans[MAXN];
int d1[] = {2, 0, -2, 0};
int d2[] = {0, 2, 0, -2};

void bfs(int x, int y, int c){
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    int cnt = 0;
    q.push({x, y});
    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        cnt++;
        for(int i = 0; i < 4; i++){
            int nx = cx + d1[i];
            int ny = cy + d2[i];
            int wx = (cx + nx) / 2;
            int wy = (cy + ny) / 2;
            if (nx <= 0 || nx >= MAXN-1 || ny <= 0 || ny >= MAXN-1) continue;
            if (wall[wx][wy]) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (c > 0) ans[c] = cnt;
}

signed main(){
    fastio;
    cin >> n;
    n++; 
    int xprev = 0, yprev = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            cin >> xprev >> yprev;
        } else {
            int x, y;
            cin >> x >> y;
            xprev *= 2;  yprev *= 2;
            x *= 2, y *= 2;
            if (xprev == x) {
                int l = min(y, yprev), h = max(y, yprev);
                for (int i = l; i <= h; i++) 
                    wall[x][i] = 1;
            } else {
                int l = min(x, xprev), h = max(x, xprev);
                for (int i = l; i <= h; i++) 
                    wall[i][yprev] = 1;
            }
            xprev = x/2;
            yprev = y/2;
        }
    }

    for(int i = 1; i < MAXN; i += 2){
        if (!visited[i][1])       bfs(i, 1,       0);
        if (!visited[i][MAXN-2])  bfs(i, MAXN-2,  0);
        if (!visited[1][i])       bfs(1, i,       0);
        if (!visited[MAXN-2][i])  bfs(MAXN-2, i,  0);
    }

    int res = 0, c = 0;
    for(int i = 1; i < MAXN; i += 2){
        for(int j = 1; j < MAXN; j += 2){
            if (!visited[i][j]) {
                ++c;
                bfs(i, j, c);
                res = max(res, ans[c]);
            }
        }
    }

    // for(int i = 1; i <= 16; i+=2){
    //     for(int j = 1; j <= 16; j += 2){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << res << "\n";
    return 0;
}
