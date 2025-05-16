#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int MAXN = 50;
int n;
int arr[MAXN];
int dp[MAXN][2];

int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) dp[i][1] = max(dp[i][1], dp[j][0]);
            else if(arr[j] > arr[i]) dp[i][0] = max(dp[i][0], dp[j][1]); 
        }
        dp[i][0]++;
        dp[i][1]++;
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    

    cout << ans << endl; 
}