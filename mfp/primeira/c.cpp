#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3*1e5;
int arr[MAXN], dp[MAXN];

//eh uma dp, agr como eu faco essa dp?
//eh basicamente a frog, soq o pulo eh de 2 em 2k+1

signed main(){
    int n; cin >> n;
    n = (1 << n)-1;
    for(int i = 1; i <= n; i++) cin >> arr[i];


    vector<int> dp(n+1, 0);
    dp[1] = arr[1];

    for(int i = 1; i <= n; i++){
        int L = 2*i, R = 2*i + 1;
        if(L <= n)
            dp[L] = max(dp[L], dp[i] + arr[L]);
        if(R <= n)
            dp[R] = max(dp[R], dp[i] + arr[R]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(dp[i], ans);
    }

    cout << ans << endl;
}