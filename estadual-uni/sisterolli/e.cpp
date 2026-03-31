
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long

signed main(){
    fastio;
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) cnt++;
    }
    if(cnt&1) cout << "AZUL\n";
    else cout << "BRANCO\n";
}