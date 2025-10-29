#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

const int MAXN = 1e3+7;
int d1[] = {0, 1, 0, -1};   // for directions: 0: Left, 1: Down, 2: Right, 3: Up
int d2[] = {-1, 0, 1, 0};

int visited[MAXN][MAXN][4];  // visited state: cell (i,j) with given direction
char grid[MAXN][MAXN];

int n, m;
bool squareVisited[MAXN][MAXN];  // tracks distinct board cells visited

// Map the characters to our directional indices.
map<char, int> mp = {
    {'L', 0},
    {'D', 1},
    {'R', 2},
    {'U', 3}
};

// This DFS simulates continuous forward motion in direction c until blocked.
// It marks each state as visited (for that direction) and also marks the cell as visited.
pair<int, int> dfs(int x, int y, int c) {
    while (true) {
        int nx = x + d1[c];
        int ny = y + d2[c];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny][c]) {
            visited[nx][ny][c] = 1;
            squareVisited[nx][ny] = true;
            x = nx;
            y = ny;
        } else {
            break;
        }
    }
    return {x, y};
}

signed main(){
    fastio;
    cin >> n >> m;
    int startX = -1, startY = -1;
    // Read grid and locate the starting position (cell that is not '.' or '#')
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] != '.' && grid[i][j] != '#'){
                startX = i;
                startY = j;
            }
        }
    }
    // Get starting direction from our mapping and mark the starting state.
    int startDir = mp[grid[startX][startY]];
    visited[startX][startY][startDir] = 1;
    squareVisited[startX][startY] = true;
    // Run DFS from the starting position in the starting direction.
    pair<int, int> initPos = dfs(startX, startY, startDir);
    
    queue<tuple<int,int,int>> q;
    // Push the state (position and direction) after the forward movement.
    q.push({initPos.first, initPos.second, startDir});
    
    // Process states in the queue.
    while(!q.empty()){
        auto [x, y, c] = q.front(); 
        q.pop();
        // From (x,y) move forward as far as possible in direction c.
        auto pos = dfs(x, y, c);
        int curX = pos.first, curY = pos.second;
        // Try turning counterclockwise (starting with (c+1)%4) until a valid move is found.
        int ndir = (c + 1) % 4;
        for (int cnt = 0; cnt < 4; cnt++){
            int nx = curX + d1[ndir];
            int ny = curY + d2[ndir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny][ndir]) {
                visited[nx][ny][ndir] = 1;
                squareVisited[nx][ny] = true;
                // Move forward in the new direction.
                pair<int,int> newPos = dfs(nx, ny, ndir);
                q.push({newPos.first, newPos.second, ndir});
                break;  // take the first valid turn
            }
            ndir = (ndir + 1) % 4;
        }
    }
    
    // Count distinct cells visited.
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (squareVisited[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
