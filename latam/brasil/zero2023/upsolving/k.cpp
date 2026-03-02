#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res *= a;
        a *= a;
        b/=2;
    }
    return res;
}

signed main(){
    fastio;
    //soma, a, b
    vector<tuple<int, int, int>> pares;
    //soma x, pares (a, b) q formam a soma x
    unordered_map<int, vector<pair<int, int>>> somas;
    for(int i = 0; i <= 216; i++){
        int x = i*i*i*i*1LL;
        for(int j = i; j <= 216; j++){
            int y = j*j*j*j*1LL;
            //aq eu guardo para uma soma, qual os valores que a formam
            pares.push_back({x+y, i, j});
            //aq eu guardo todas os pares possiveis q formam essa soma
            somas[x+y].push_back({i,j});
        }
    }

    sort(pares.begin(), pares.end());
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        vector<array<int, 4>> sol;
        //basta pesquisar a existencia dessa soma
        for(auto& [soma, a, b] : pares){
            if(soma > n) break;
            int t = n - soma;
            auto it = somas.find(t);
            if(it == somas.end()) continue;
            for(auto& [c, d] : it->second){
                if(b <= c){
                    sol.push_back({a, b, c, d});
                }
            }
        }

        sort(sol.begin(), sol.end());

        cout << sol.size() << endl;
        for(auto& [a, b, c, d]: sol){
            cout << a << " " << b << " " << c << " " << d << endl;
        }

    }
}