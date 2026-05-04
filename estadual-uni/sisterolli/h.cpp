#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 1e4+7;
int grid[MAXN][MAXN];
int x, y, k;

bool check(int r){
    int x1 = max(1, x+1-r);
    int x2 = min(10001, x+1+r);
    int y1 = max(1, y+1-r);
    int y2 = min(10001, y+1+r);
    int sum = grid[x2][y2] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x1-1][y1-1];
    return sum >= k;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a++, b++;
        grid[a][b]++;
    }

    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }

    while(m--){
        cin >> x >> y >> k;
        int l = 0, r = MAXN;
        int ans = MAXN;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid)){
                ans = mid;
                r = mid-1;
            }else l = mid+1;
        }

        cout << ans << endl;
    }
}

int main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
    return 0;
}