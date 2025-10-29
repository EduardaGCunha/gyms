#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 5*(1e3)+7;
int dp[MAXN][MAXN];
 
int main(){
    string s, t; cin >> s >> t;
    dp[0][0] = 1;
    for(int i = 0; i <=  (int) s.size(); i++){
        dp[i][0] = i;
        for(int j = 0; j <= (int) t.size(); j++){
            dp[0][j] = j;
            if(i - 1 >= 0 && j-1 >= 0){
                dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1] + (s[i-1] != t[j-1])});
            }
        }
    }
 
    cout << dp[(int)s.size()][(int)t.size()] << endl;
}