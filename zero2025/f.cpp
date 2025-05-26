#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int MAXN = 4000; 
const int MAXS = 8001;     
int dp[5][MAXS];

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    dp[0][MAXN] = 1;
    for(int i = 0; i < n; i++){
        for(int k = 3; k >= 0; --k){
            for(int s = 0; s < MAXS; ++s){
                //cout << "entrou nesse loop\n";
                int res = dp[k][s];
                if(!res) continue;
                int x = s + arr[i];
                if(x < 0 || x >= MAXS) continue;
                dp[k+1][x] += res;
                //cout << res << endl;
            }
        }
    }

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 50; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int ans = 0;
        int idx = x + MAXN;
        //cout << idx << endl;
        if(idx >= 0 && idx < MAXS) ans = dp[4][idx];
        cout << ans << endl;
    }

    return 0;
}
