#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int INF = 1e3;
const int MAXN = 103;
vector<int> graph[MAXN];


signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i-1], dp[max(i-k, 0LL)] + arr[i]);
    }
    cout << dp[n] << endl;

}