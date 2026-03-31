#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long

const int MAXN = 1e6+7;
vector<int> graph[MAXN];
int arr[MAXN];
int n, b, l, cur;

/*
consigo determinar quem vai ser os filhos baseado na qtd de vertices atuais nesse nivel
qtd vai ser qtd_anterior*b

vertice filho de cada possivel node eh 
*/

signed main(){
    fastio;
    cin >> n >> b >> l;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int curst = 0;
    int sz = 1;
    vector<int> dp(n+7, 0);
    dp[0] = arr[0];
    for(int i = 0; i < l-1; i++){
        int nxtst = curst + sz;
        int nxtsz = sz*b; 
        
        //para cada tam
        for(int j = 0; j < nxtsz; j++){
            int idx = nxtst + j;
            int p = curst + (j % sz);

            dp[idx] = arr[idx] + dp[p];
        }

        sz = nxtsz;
        curst = nxtst;
    }

    int ans = -2e18;
    for(int i = curst; i < n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}