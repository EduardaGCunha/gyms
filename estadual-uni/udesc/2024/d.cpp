#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans = max(ans, x+1+i);
    }
    cout << ans << endl;
}
