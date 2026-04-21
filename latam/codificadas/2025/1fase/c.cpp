#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n; cin >> n;
    map<string, int> freq;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            string s; cin >> s;
            freq[s]++;
        }
    }

    vector<pair<int, string>> v;
    for(auto [s, cnt] : freq){
        if(cnt >= n) v.push_back({cnt, s});
    }

    sort(v.rbegin(), v.rend());
    for(auto [cnt, s] : v){
        cout << s << endl;
    }
}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}