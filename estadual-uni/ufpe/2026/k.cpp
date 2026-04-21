#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            arr[x][i]++;
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] += arr[i][j-1];
        }
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        int pos = 0;
        for(int i = 1; i <= m; i++){
            int pr = arr[i][r] - arr[i][l-1];
            if(!pr){
                pos = 1;
                cout << i << " ";
            }
        }
        if(!pos) cout << -1;
        cout << endl;
    }
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}