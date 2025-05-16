#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int ans = -1e9;
    vector<int> dp(55, 1);
    for(int i = 1; i < s.size(); i++){
        for(int j = 0; j < i; j++){
            if(s[j] < s[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    for(int i = 0; i < s.size(); i++) ans = max(ans, dp[i]);
    cout << 26 - ans << endl;
}