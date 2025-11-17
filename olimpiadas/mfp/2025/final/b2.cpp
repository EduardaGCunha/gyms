#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
int arr[MAXN];
int n;

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0;
    vector<int> dp(n+2, 0);
    for (int i = n-1; i >= 0; i--) {
        sum += arr[i];
        dp[i] = sum - min(dp[i+1], dp[i+2]);
    }

    cout << dp[0] << endl;
}

signed main() {
    int t; cin >> t;
    while(t--){
        solve();                    
    }
}