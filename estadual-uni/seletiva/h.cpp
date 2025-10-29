#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
 
signed main(){
    fastio;
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, cnt = 1;
    int aa = 0, bb = 0;
    for (int i = 1; i < n; i++){
        //cout << aa << " " << bb << cnt << endl;
        if (s[i] == s[i - 1]) cnt++;
        else {
            if (s[i - 1] == 'a') aa = cnt;
            else bb = cnt;
            cnt = 1;
        }
        if (s[i] == 'b'){
            if (cnt + bb >= aa) ans = max(ans, aa * 2);
            else if (aa >= cnt) ans = max(ans, cnt * 2);
            //cout << bb << " " << cnt << endl;
        } else {
            if (cnt + aa >= bb) ans = max(ans, bb * 2);
            else if (bb >= cnt) ans = max(ans, cnt * 2);
        }
    }
    cout << ans << endl;
}
 