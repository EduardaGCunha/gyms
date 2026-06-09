#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    string s, t; cin >> s >> t;
    string ans = (((int)s.size() + (int)t.size())&1) ? "NO MATCH" : "MATCH";
    cout << ans << endl;
}   
