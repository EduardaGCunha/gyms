#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 2*(1e3)+7;
int dp[MAXN][MAXN];

int main(){
    int tt; cin >> tt;
    while(tt--){
        string s, t; cin >> s >> t;
        int n = s.size();
        int m = t.size();
        
        memset(dp, 0, sizeof(dp));
    
        for(int i = 0, cnt = 0; i <= max(n, m); i++, cnt++){
            dp[i][0] = cnt;
            dp[0][i] = cnt;
        }
    
        //dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int mn = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                    dp[i][j] = mn;
                }
            }
        }
    
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    
        cout << dp[n][m] << endl;
    }
}