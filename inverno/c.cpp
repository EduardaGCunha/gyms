#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n; cin >> n;
    if(n%2 == 0 || n%5 == 0){
        cout << "Y\n";
        return;
    }

    while(n >= 5){
        n -=5;
        if(!(n&1)){
            cout << "Y\n";
            return;
        }
    }

   cout << "N\n";
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}