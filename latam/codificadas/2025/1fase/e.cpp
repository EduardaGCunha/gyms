#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a == 1){
        int ans = ((d-c)/b)+1; 
        cout << ans << endl; 
        return;
    }
    int qtd = c, ans = 0;
    while(qtd <= d){
        ans++;
        qtd = qtd*a + b;
    }
    cout << ans << endl;
}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}