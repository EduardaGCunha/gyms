#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
no maximo 1e5 strings com tamanho no maximo 10
o que faco com caso de tamanho impar?, pq meio q nn me importa o ultimo digito
eu so checo se existe qualquer um dos 26 caracteres com aquele prefixo dos 
m/2 - 1 caracteres!! se existir, entao basta que eu adicione na resposta

*/ 

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    map<vector<int>, int> mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int k = m/2;
        vector<int> v, c;
        for(int j = 0; j < k; j++){
            //s[n - i] - s[i] = t[n - i] - t[i]
           int a = s[j]-'a', b = s[m-j-1]-'a';
           v.push_back({(b - a + 26)%26});
        }
        mp[v]++;
    }

    for(auto u : mp){
        vector<int> v2;
        for(auto v : u.first){
            v2.push_back({(26 - v)%26});
        }

        ans += u.second*mp[v2];
    }
    cout << ans << endl;
}