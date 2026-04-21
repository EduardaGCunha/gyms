#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    string s; cin >> s;
    map<char, int> freq;
    int n = s.size();
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
    }

    if(freq['T'] == freq['S'] && freq['S'] == freq['C']) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}