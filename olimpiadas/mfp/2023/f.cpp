#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n; cin >> n;
    string s; cin >> s;
    map<int, int> freq;
    int cur = 0, ans = 0;
    freq[0]++;
    for(int i = 0; i < n; i++){
        cur ^= (1 << (s[i]-'a'));
        ans += freq[cur];
        // for(int j = 0; j < 8; j++){
        //     ans += freq[(cur ^ (1 << j))];
        // }
        freq[cur]++;
    }

    cout << ans << endl;

}