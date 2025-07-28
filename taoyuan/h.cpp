#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e3 + 7;
int dp[MAXN];

signed main() {
    fastio;
    int c; cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> val, w;
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int x;
        while (iss >> x) val.push_back(x);
    }
    int n = val.size(); 
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        w.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        for (int j = c; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
        }
    }

    int ans = 0;
    for (int j = 0; j <= c; j++) {
        ans = max(ans, dp[j]);
    }

    cout << ans << endl;
    return 0;
}
