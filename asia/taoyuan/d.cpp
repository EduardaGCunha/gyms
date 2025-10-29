#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 101;

int pos1[4] = {0, 1, 0, -1};
int pos2[4] = {1, 0, -1, 0};
int diagx[4] = {1, -1, 1, -1};
int diagy[4] = {1, -1, -1, 1};


void solve(){
    int n, m, d1, d2; cin >> n >> m >> d1 >> d2;

    vector<vector<char>> grid(n, vector<char>(m, '.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'V'){
                for(int k = 0; k < 4; k++){
                    int dx = i + pos1[k];
                    int dy = j + pos2[k];
                    if(dx < 0 || dx >= n) continue;
                    if(dy < 0 || dy >= m) continue;
                    char v = d1 + '0';
                    //se for um ponto so adiciono o valor
                    if(grid[dx][dy] == '.') grid[dx][dy] = v;
                    //se for um V entao continue
                    else if(grid[dx][dy] == 'V') continue;
                    else{
                        //
                        int val = grid[dx][dy] - '0';
                        if(val > d1) continue;
                        grid[dx][dy] = v;
                    }
                }

                for(int k = 0; k < 4; k++){
                    int dx = i + diagx[k];
                    int dy = j + diagy[k];
                    if(dx < 0 || dx >= n) continue;
                    if(dy < 0 || dy >= m) continue;
                    char v = d2 + '0';
                    if(grid[dx][dy] == '.') grid[dx][dy] = v;
                    else if(grid[dx][dy] == 'V') continue;
                    else{
                        int val = grid[dx][dy] - '0';
                        if(val > d2) continue;
                        grid[dx][dy] = v;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.') grid[i][j] = '0';
            cout << grid[i][j];
        }
        cout << endl;
    }
}

signed main() {
    fastio;
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Airplane #" << i << ":\n";
        solve();
    }
}