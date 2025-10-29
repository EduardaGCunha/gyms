#include <bits/stdc++.h>
using namespace std;

const int ZAP = 998244353;
const int MAXN = 4e3+7;
int dp[MAXN];

int main(){
    int n, k; cin >> n >> k;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        if(i == k) continue;
        for(int j = i; j <= n; j++){
            dp[j] = (dp[j] + dp[j-i])%ZAP;
        }
    }
    cout << dp[n] << endl;
}