#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    //idx, valor, dir
    queue<tuple<int, int, int>> q;
    int arr[n];
    vector<int> ans(n, -1), fixed(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] != -1){
            ans[i] = arr[i];
            fixed[i] = 1;
            q.push({i-1, arr[i]+1, -1});
            q.push({i+1, arr[i]+1, +1});
        }
    }

    while(!q.empty()){
        auto [idx, v, dir] = q.front(); q.pop();
        if(idx < 0 || idx >= n || fixed[idx]) continue;
        if(ans[idx] != -1 && ans[idx] < v) continue;
        ans[idx] = v;
        q.push({idx+dir, v+1, dir});
    }

    for(auto u : ans) cout << u << " ";
    cout << endl;
}

signed main(){
    fastio;
    solve();
}