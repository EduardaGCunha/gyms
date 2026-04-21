#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 1e3+7;
char grid[MAXN][MAXN];
int n, m;

bool solve(int x, int y) {
    int tam = 0;
    while (y < m && grid[x][y] == '*') {
        y++; 
        tam++;
    }
    if (tam < 2) return false;
    y--;

    tam = 0;
    while (x < n && grid[x][y] == '*') {
        x++; 
        tam++;
    }
    if (tam < 3) return false;
    x--; 
    tam = 0;
    while (y >= 0 && grid[x][y] == '*') {
        y--; 
        tam++;
    }
    if (tam < 2) return false;
    y++; 

    tam = 0;
    while (x < n && grid[x][y] == '*') {
        x++; 
        tam++;
    }
    if (tam < 3) return false;
    x--; 

    tam = 0;
    while (y < m && grid[x][y] == '*') {
        y++; 
        tam++;
    }
    if (tam < 2) return false;
    return true;
}

signed main(){
    fastio;
    cin >> n >> m;
    int x = -1, y = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '*' && x == -1){
                x = i;
                y = j;
            }
        }
    }

    if(solve(x, y)) cout << "Double Petal Flower\n";
    else cout << "Triple Corolla Flower\n";
}