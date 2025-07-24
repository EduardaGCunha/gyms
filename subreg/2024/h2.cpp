#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
vou pegar todas as posições tal que 
*/

signed main() {
    fastio;
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++){
        if(s[i] == '*') pos.push_back({i, 1});
    }

    for(int i = 0; i < m; i++){
        if(t[i] == '*') pos.push_back({i, 0});
    }

    int tot = pos.size();
    for(int i = 0; i < (1 << tot); i++){
        string a = s, b = t;
        for(int j = 0; j < tot; j++){
            if(i&(1 << j)){
                if(pos[j].second) a[pos[j].first] = '1';
                else b[pos[j].first] = '1';
            }else{
                if(pos[j].second) a[pos[j].first] = '0';
                else b[pos[j].first] = '0';
            }
        }
        //cout << a << endl;
        //cout << b << endl;
        //passando pelo divisor e calculando o valor dele
        int val = 0, res = 0;
        for(int j = 0; j < m; j++){
            val = (val*2 + b[j]-'0');
        }

        //passando pelo dividendo
        for(int j = 0; j < n; j++){
            res = (res*2 + a[j]-'0')%val;
        }

        if(!res){
            cout << a << endl;
            return 0;
        }
    }
}