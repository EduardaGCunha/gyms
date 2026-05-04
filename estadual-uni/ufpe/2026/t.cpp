#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MOD = 998244353;

void solve(){
    int k = 7;
    while(true){
        if(!(k%7) && k%2 == 1 && k%3 == 1 && k%4 == 1 && k%5 == 1 && k%6 == 1){
            cout << k << endl;
            break;
        }
        k++;
    }
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}