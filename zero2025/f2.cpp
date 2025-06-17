#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

/*
somo 4000 nos valores so p ter ctz q nn vou ter q lidar com negativo
tenho no maximo 4 caras
a qtd de maneiras de fazer uma soma x eh a qtd de fazer soma-x com -1 caras
*/

const int MAXN = 4000;
const int MAXS = 8001;

int dp[5][MAXS];
int arr[MAXN];

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    dp[0][MAXN] = 1;
    for(int i = 0; i < n; i++){
        for(int k = 3; k >= 0; k--){
            for(int s = 0; s < MAXS; s++){
                int res = dp[k][s];
                if(!res) continue;
                int x = s + arr[i];
                if(x < 0 || x >= MAXS) continue;
                dp[k+1][x] += res;
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        int ans = 0;
        int idx = x + MAXN;
        if(idx >= 0 && idx < MAXS) ans = dp[4][idx];
        cout << ans << endl;
    }

}