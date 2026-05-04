#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

const int MAXN = 10;
vector<int> graph[MAXN];

// 1. ADDED: Declare the memoization table
map<pair<int, vector<int>>, int> memo;

int ganha(vector<int> g){
    vector<vector<int>> grid(3, vector<int>(3, 100));
    for(int i = 0; i < 3; i++){
        grid[0][i] = g[i]; 
        grid[1][i] = g[i+3];
        grid[2][i] = g[i+6];
    }

    for(int i = 0; i < 3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][2] != 100) return grid[i][2];
    }

    for(int i = 0; i < 3; i++){
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[2][i] != 100) return grid[2][i];
    }

    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] != 100) return grid[2][2];

    if(grid[2][0] == grid[1][1] && grid[0][2] == grid[1][1] && grid[1][1] != 100) return grid[1][1];

    return 2;
}

int dfs(vector<int> grid, int mask, int v, int turno, vector<int> indeg){
    mask |= (1<<v);
    grid[v] = turno;
    
    int x = ganha(grid);
    if(x != 2) return x;
    
    if(mask == ((1<<9) -1)) return 2;

    if(memo.count({mask, grid})) return memo[{mask, grid}];

    for(auto u : graph[v]){
        if(indeg[u] > 0) indeg[u]--; 
    }

    // 2. FIXED: Minimax logic for the next player making a move
    int nxt = !turno;
    int best_ans = turno; // The worst-case scenario for `nxt` is that `turno` wins
    bool possible_move = false;

    for(int i = 0; i < 9; i++){
        if(!(mask &(1<<i)) && indeg[i] == 0){
            possible_move = true;
            int res = dfs(grid, mask, i, nxt, indeg);
            
            if(res == nxt) return memo[{mask, grid}] = nxt; // Next player finds a guaranteed win
            if(res == 2) best_ans = 2; // Next player can at least force a draw
        }
    }

    if(!possible_move) return memo[{mask, grid}] = 2;
    return memo[{mask, grid}] = best_ans;
}

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> indeg(10, 0), visited(10, 0);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        indeg[b]++;
        graph[a].push_back(b);
    }

    queue<int> q;
    vector<int> indeg2(10, 0);
    for(int i = 0; i < 9; i++){
        indeg2[i] = indeg[i];
        if(indeg[i] == 0){
            q.push(i);
            visited[i] = 1;
        }
    }

    int mask = 0;
    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(!(--indeg[u])){
                q.push(u);
                visited[u] = 1;
            }
        }
    }

    for(int i = 0; i < 9; i++){
        if(!visited[i]) mask |= (1<<i);
    }

    vector<int> grid(10, 100);
    
    // 3. FIXED: Minimax logic for Player 0 (Xavier) in the first turn
    int best_ans = 1; // Worst case for Player 0 is Player 1 winning
    bool possible_move = false;
    
    for(int i = 0; i < 9; i++){
        if(indeg2[i] == 0 && !(mask & (1<<i))){
            possible_move = true;
            int v = dfs(grid, mask, i, 0, indeg2);
            if(v == 0){ 
                cout << "X\n";
                return 0;
            }
            if(v == 2) best_ans = 2; 
        }
    }

    // Catch situations where the board is completely locked off from the start
    if(!possible_move || best_ans == 2) cout << "E\n";
    else cout << "O\n";
    
    return 0;
}