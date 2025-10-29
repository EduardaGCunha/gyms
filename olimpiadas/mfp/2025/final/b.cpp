#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n+2), suf(n+3, 0);
        int sum = 0;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        for(int i = n; i >= 1; i--){
            suf[i] = suf[i+1] + arr[i];
        }

        vector<int> dp(n+3, 0);
        for(int i = n; i >= 1; i--){
            dp[i] = max(arr[i] + (suf[i+1] - dp[i+1]), arr[i] + arr[i+1] + (suf[i+2] - dp[i+2]));
        }
        cout << dp[1] << endl;
    }
}