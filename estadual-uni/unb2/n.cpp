#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    vector<int> suf(m+2, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        suf[x]+=x;
    }

    for(int i = m-1; i >= 0; i--){
        suf[i] += suf[i+1];
    }

    for(int i = 1; i <= m; i++) cout << suf[i] << " ";
    cout << endl;

}

signed main() {
    fastio;
    solve();
    return 0;
}