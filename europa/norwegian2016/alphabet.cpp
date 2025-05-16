#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;
int dp[MAXN][MAXN];

int main(){
    string s; cin >> s;
    string abc = "“abcdefghijklmnopqrstuvwxyz";

    
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= abc.size(); j++){
            if(s[i-1] == abc[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << 26 - dp[s.size()][abc.size()] << endl;
}