#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

struct ordem{
    int pont;
    string a;
    bool operator<(const ordem &other){
        if(pont == other.pont) return a < other.a;
        return pont > other.pont;
    }
};

signed main(){
    fastio;
    int n; cin >> n;
    //palavra to pontuador
    map<string, string> mp; 
    map<string, int> pontuacao;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        pontuacao[s] = 0;
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            string t; cin >> t;
            mp[t] = s;
        }
    }

    int k; cin >> k;
    for(int i = 0; i < k; i++){
        string a; cin >> a;
        if(mp.find(a) != mp.end()){
            pontuacao[mp[a]]++;
        }
    }

    vector<ordem> v;
    for(auto u : pontuacao){
        ordem i;
        i.a = u.first;
        i.pont = u.second;
        v.push_back(i);
    }

    sort(v.begin(), v.end());
    cout << v[0].a << endl;
    
}