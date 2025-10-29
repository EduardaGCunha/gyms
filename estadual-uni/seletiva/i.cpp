#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

const int MAXN = 1e3+7;
int d1[] = {0, -1, 0, 1};  
int d2[] = {1, 0, -1, 0};

int n, m;
char grid[MAXN][MAXN];

map<char,int> mp = {
    {'R', 0},
    {'U', 1},
    {'L', 2},
    {'D', 3}
};

signed main(){
    fastio;
    cin >> n >> m;
    int stx = -1, sty = -1, c;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] != '#' && grid[i][j] != '.'){
                stx = i;
                sty = j;
                c = mp[grid[i][j]];
            }
        }
    }

    set<tuple<int,int,int>> visited2;
    set<pair<int,int>> visited;
    
    int x = stx, y = sty;
    visited.insert({x, y});
    visited2.insert({x, y, c});
    
    while (1) {
        int dx1 = x + d1[c];
        int dx2 = y + d2[c];
        
        if(dx1 >= 0 && dx1 < n && dx2 >= 0 && dx2 < m && grid[dx1][dx2] != '#'){
            tuple<int,int,int> nxt = {dx1, dx2, c};
            if(visited2.count(nxt))
                break;
            visited2.insert(nxt);
            visited.insert({dx1, dx2});
            x = dx1;
            y = dx2;
        } 
        else {
            int found = 0;
            for (int i = 1; i <= 4; i++){
                int dir = (c + i) % 4;
                tuple<int,int,int> cur = {x, y, dir};
                if(visited2.count(cur)){
                    cout << visited.size() << endl;
                    return 0;
                }
                visited2.insert(cur);
                
                int dx = x + d1[dir];
                int dy = y + d2[dir];
                if(dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] != '#'){
                    tuple<int,int,int> nxt = {dx, dy, dir};
                    if(visited2.count(nxt)){
                        cout << visited.size() << endl;
                        return 0;
                    }
                    visited2.insert(nxt);
                    visited.insert({dx, dy});
                    x = dx;
                    y = dy;
                    c = dir;
                    found = 1;
                    break;
                }
            }
            if(!found) break;
        }
    }
    
    cout << visited.size() << endl;
}
