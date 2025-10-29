#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        int x; cin >> x;
        cnt += x;
    }
    int b; cin >> b;
    if(!b && (cnt&1) || b && !(cnt&1)) cout << "S\n";
    else cout << "N?\n";
}


signed main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}