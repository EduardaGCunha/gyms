#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
mes = 30 dias
ano = 360 dias
*/

signed main() {
    fastio;
    int n; cin >> n; 
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    int mn = LLONG_MAX, mx = 0;
    for(int i = 0; i < n-1; i++){
        auto [a, b, c] = v[i];
        auto [x, y, z] = v[i+1];
        int tot = 0;
        tot += abs(a-x);
    }
}