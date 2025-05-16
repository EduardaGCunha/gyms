#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 55;
int dp[MAXN][2];

signed main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)  cin >> arr[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) dp[i][1] = max(dp[i][1], dp[j][0]);
            else if (arr[j] > arr[i]) dp[i][0] = max(dp[i][0], dp[j][1]);
        }
        dp[i][0]++;
        dp[i][1]++;
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    
    cout << ans << endl;
}
