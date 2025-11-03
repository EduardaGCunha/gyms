#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

bool solve(){
    string s; cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int l = 0, d = 0;
    for(auto u : s){
        if(u >= '0' && u <= '9') d = 1;
        if((u >= 'a' && u <= 'z')) l = 1;
    }
    return (s == t && l && d && s.size() > 10);
}

signed main() {
    fastio;
    int t; cin >> t;
    while(t--){
        if(solve()) cout << "S\n";
        else cout << "N\n";
    }
}