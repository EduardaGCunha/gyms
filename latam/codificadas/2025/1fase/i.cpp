#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e3+7;
char grid[MAXN][MAXN];
int n, m, x, y, total_q = 0, t = 0;
vector<vector<int>> tin, low;
vector<vector<bool>> visited;
vector<vector<bool>> is_art;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'Q';
}

bool dfs(int r, int c, int pr, int pc) {
    visited[r][c] = true;
    tin[r][c] = low[r][c] = t++;
    bool has_q_subtree = (grid[r][c] == 'Q');
    int children = 0;

    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr == pr && nc == pc) continue;
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 'Q') {
            if (visited[nr][nc]) {
                low[r][c] = min(low[r][c], tin[nr][nc]);
            } else {
                children++;
                bool found_q = dfs(nr, nc, r, c);
                low[r][c] = min(low[r][c], low[nr][nc]);
                
                if (pr != -1 && low[nr][nc] >= tin[r][c] && found_q && grid[r][c] == 'Q') {
                    is_art[r][c] = true;
                }
                has_q_subtree |= found_q;
            }
        }
    }
    return has_q_subtree;
}

void solve() {
    cin >> n >> m;
    is_art.assign(n, vector<bool>(m, false));
    visited.assign(n, vector<bool>(m, false));
    tin.assign(n, vector<int>(m, -1));
    low.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
            if (grid[i][j] == 'H') { x = i; y = j; }
            else if (grid[i][j] == 'Q') total_q++;
        }
    }

    if (total_q == 0) { 
        cout << -1 << endl; 
        return; 
    }

    dfs(x, y, -1, -1);

    int reached_q = 0;
    bool has_far_q = false;
    bool found_art = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'Q') {
                if (visited[i][j]) {
                    reached_q++;
                    if (abs(i - x) + abs(j - y) > 1) has_far_q = true;
                }
                if (is_art[i][j]) found_art = true;
            }
        }
    }

    if (reached_q < total_q) {
        cout << 0 << endl;
    } 
    else if (!has_far_q) {
        cout << -1 << endl;
    } 
    else if (found_art) {
        cout << 1 << endl;
    } 
    else {
        cout << 2 << endl;
    }
}

signed main() {
    fastio;
    solve();
    return 0;
}