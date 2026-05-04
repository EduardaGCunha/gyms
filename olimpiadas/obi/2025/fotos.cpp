#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr;
    arr.push_back(0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x) arr.push_back(i);
    }
    //cout << endl;
    arr.push_back(n+1);

    // for(auto u : arr) cout << u << " ";
    // cout << endl;

    int ans = 0;

    for(int i = 1; i < arr.size()-1; i++){
        ans += (arr[i]-arr[i-1])*(arr[i+1]-arr[i]);
    }
    cout << ans << endl;
}

signed main(){
    fastio;
    solve();
}