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
    vector<int> val;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        int x = a + b*30 + c*360;
        val.push_back(x);
    }

    sort(val.begin(), val.end());

    int mn = INT_MAX, mx = 0;
    for(int i = 1; i < n; i++){
        mn = min(mn, val[i]-val[i-1]);
        mx = max(mx, val[i]-val[i-1]);
    }
    cout << mn << " " << mx << endl;

}