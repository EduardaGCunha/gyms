#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> freq;
    int ans = 0;
    for(int i =0; i < n; i++){
        int x; cin >> x;
        if(k%x) continue;
        ans += freq[k/x];
        freq[x]++;
    }
    cout << ans << endl;

}

signed main() {
    fastio;
    solve();
    return 0;
}