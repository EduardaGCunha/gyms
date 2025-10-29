#include <bits/stdc++.h>
using namespace std;

const int ZAP = 998244353;
const int MAXN = 4e3+7;
int dp[MAXN][MAXN];

int main(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 0;
        dp[0][i] = 1;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            if(j != k && i - j >= 0){ 
                dp[i][j] = (dp[i-j][j] + dp[i][j])%ZAP;
            }
        }
    }
    cout << dp[n][n] << endl;
}