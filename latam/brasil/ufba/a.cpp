#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'
#define dbg(x) cout << x << " ";

/*
o tamandua nao vai embora
se ele nao consegue comer inteiro, vc guarda o quanto ele ainda pode comer
ent se tiver algum tamandua que pode comer um ainda, vc escolhe q ele coma
*/
signed main(){
    int n; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(arr[i] <= 1){
            dp[i] = dp[i-1];
            continue;
        }
        int soma = 0;
        for(int j = i; j > 0; j--){
            soma += arr[j];
            int v = 0;
            if(j-2 >= 0) v = dp[j-2];
            dp[i] = max(dp[i], v + soma - (i-j+1)*(i-j+1));
            //dbg(i); dbg(j); dbg(soma); dbg((i-j+1)*(i-j+1)); dbg(dp[i]);
           // cout << endl;
        }
    }

    // for(int i = 1; i<= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    cout << dp[n] << endl;
}
