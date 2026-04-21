#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int a, b; cin >> a >> b;
    if(a <= 0 && b >= 0){
        cout << "Y\n";
    }else if(a > 0 ) cout << "Y\n";
    else{
        int qtd = b - a + 1;
        if(qtd&1) cout << "N\n";
        else cout << "Y\n";
    }
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}