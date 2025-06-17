#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int m; cin >> m;
    int tot = m*1e6*8*1LL;
    int ans = 0;
    if(tot > 0) ans = 64 - __builtin_clzll(tot);
    cout << ans << endl;
}