#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }

    map<pair<int, int>, int> freq;
    for(int i = 0; i < n; i++){
        auto [x1, y1] = v[i];
        for(int j = i+1; j < n; j++){
            auto [x2, y2] = v[j];
            int sx = x1+x2;
            int sy = y1+y2;
            freq[{sx, sy}]++;
            if(freq[{sx, sy}] >= 2){
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}