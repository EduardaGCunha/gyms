#include <bits/stdc++.h>
using namespace std;

#define int long long
 
const int MOD = 1e9+7;
const int MAXN = 1501;
int dp[MAXN][MAXN];
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x; cin >> n >> x;
    int amy; cin >> amy;
    int m = n-1;
    int arr[m];
    for(int i = 0; i < m; i++) cin >> arr[i];

    sort(arr, arr+m);

    for(int s = x-1; s>=0; s--){
        for(int j = m-1; j >= 0; j--){
            if(arr[j] > s) dp[j][s] = dp[j+1][s];
            else{
                int exc = 0;
                if(s + arr[j] >= x) exc = 1;
                else exc = dp[j+1][s+arr[j]];
                dp[j][s] = (exc + dp[j+1][s])%MOD;
            }
        }
    }

    cout << (dp[0][amy])%MOD << endl;
}
