#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = LLONG_MIN;
const int MAXN = 1e5+7;
int dp[MAXN], s[MAXN], e[MAXN];

int n, x, k;

int pd(int idx){
    if(idx >= n) return 0;
    if(dp[idx] != INF) return dp[idx];
    return dp[idx] = max(pd(idx+1) + e[idx]-s[idx], pd(idx+k) - x);
}

signed main(){
    fastio;
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) dp[i] = INF;
    for(int i  =0;  i< n; i++){
        cin >> s[i] >> e[i];
    }
    cout << max(0LL, pd(0)) << endl;
}   
