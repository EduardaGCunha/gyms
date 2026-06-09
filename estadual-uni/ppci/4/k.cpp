#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int l = 0, r = n-1;
        while(r-l > 1 && s[l] == s[r]) l++, r--;
        if(l == r) cout << "SIM\n";
        else if(l == r-1 && s[l] == s[r]) cout << "SIM\n";
        else cout << "NAO\n";
    }
}   
