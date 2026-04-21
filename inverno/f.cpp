#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int a, b, n; cin >> a >> b >> n;
    vector<int> fib(n+1, 0);
    fib[0] = a;
    fib[1] = b;
    for(int i =2; i <= n; i++){
        fib[i] = (fib[i-1]+1)^(fib[i-2]);
    }
    cout << fib[n-1] << endl;
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}