#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n; cin >> n;
    map<int, int> mp;
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(mp[x] == 0){
            //se for um valor novo, significa q eu adicionei um 
            //numero distinto de qualquer forma
            dp[i] = dp[i-1]+1;
        }else{
            //eh melhor continuar com esse numero distinto e adicionar 1 na contagem
            //ou transformar o intervalo [l, i] em 1 so e nn adicionar na resposta?
            dp[i] = min(dp[mp[x]], dp[i-1]+1);
        }
        mp[x] = i;
    }
    cout << dp[n] << endl;
}