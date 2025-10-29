#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int cnt = 0, tog = 0;
    int tot = 0, cur = 0;
    for(int i = 0; i < n; i++){
        cur += ((s[i]-'0')*(pow(10, cnt)));
        cnt++;
        if(cnt == 3){
            if(tog) tot -= cur;
            else tot += cur;
            cur = 0;
            tog = !tog;
            cnt = 0;
        }
    }
    if(cnt > 0){
        if(tog) tot -= cur;
        else tot += cur;
    }
    cout << abs(tot) << " ";
    if(!(tot%13)) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}