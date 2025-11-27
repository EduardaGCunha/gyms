#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 18;
int brr[MAXN];
int dp[(1<<MAXN)+7][102];

/*
dp guarda o pai para chegar na bitmask mask com valor v
isso so acontece quando b[i]/x 
ent o p = x
e o valor v = b[i]/x
meio q faz o grafo de conexao entre x e v p/ poder fazer backtracking
*/

void solve(){
    int m; cin >> m;
    int n = m-1;
    for(int i = 0; i < n; i++) cin >> brr[i];

    for(int i = 0; i < (1 << m); i++) {
        for(int j = 0; j <= 100; j++) {
            dp[i][j] = -2;
        }
    }
    //consigo montar esses valores como inicias
    for(int i = 1; i <= 100; i++) dp[0][i] = -1; 
    //p todas as masks
    int tot = (1<<n);
    for(int i = 0; i < tot; i++){
        for(int x = 1; x <= 100; x++){
            //nn eh um estado alcancavel
            if(dp[i][x] == -2) continue;
            //p cada bag
            for(int j = 0; j < n; j++){
                if(i&(1<<j)) continue;
                if(!(brr[j]%x)){
                    int v = brr[j]/x; 
                    if(v >= 1 && v <= 100){
                        int newmask = i | (1<<j);
                        dp[newmask][v] = x; 
                    }
                }
            }
        }
    }

    int ult = -1;

    for(int i = 1; i <= 100; i++){
        if(dp[tot-1][i] != -2) ult = i;
    }

    if(ult == -1){
        cout << "No\n";
    }else{
        cout << "Yes\n";
        vector<int> ans;
        int cur = ult;
        int mask = tot-1;

        while(mask > 0){
            ans.push_back(cur);

            int prev = dp[mask][cur];
            int achou = -1;
            for(int j = 0; j < n; j++){
                if((mask & (1 << j)) && brr[j] == prev * cur){
                    achou = j;
                    break;
                }
            }

            mask ^= (1 << achou);
            cur = prev;
        }   
        ans.push_back(cur);

        for(auto u : ans) cout << u << " ";
        cout << endl;
    }
}

signed main() {
    fastio;
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
