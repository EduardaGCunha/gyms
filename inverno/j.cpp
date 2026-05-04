#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> barcos;
    map<int, multiset<int>> mp;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        barcos.push_back({a, b, c});
    }

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        mp[x].insert(y);
    }

    //p cada barco  
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto [x, r, y] = barcos[i];
        int rmin = x-r;
        int rmax = x+r;
        //p cada raio, vo checar e remover o peixe correspondente
        for(int j = rmin; j <= rmax; j++){
            set<int> rem;
            for(auto yp : mp[j]){
                if(yp <= y){
                    rem.insert(yp);
                    ans++;
                }else if((yp - y)*(yp-y) + (j-x)*(j-x) <= r*r){
                    rem.insert(yp);
                    ans++;
                }else break;
            }

            for(auto u : rem) mp[j].erase(u);
        }
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}