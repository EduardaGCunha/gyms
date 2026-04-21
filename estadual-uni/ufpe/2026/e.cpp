#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n = 8;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == '.') cnt++;
            else{
                if(cnt) cout << cnt;
                cnt = 0;
                cout << s[j];
            }
        }
        if(cnt) cout << cnt;
        if(i != n-1) cout << '/';
    }
    cout << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}