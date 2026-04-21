#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n; cin >> n;
    map<int, int> freq;
    set<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
        freq[x]++;
    }

    int ans = 0;
    for(auto u : arr){
        ans += freq[u] * freq[u+1];
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}