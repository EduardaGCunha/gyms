#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int prosa, pazul, n; cin >> prosa >> pazul >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, prosa*i+pazul*n-i);
    }
    cout << ans << endl;
}