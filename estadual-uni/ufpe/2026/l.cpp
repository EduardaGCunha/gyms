#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

struct DSU {
    int n;
    vector<int> p, r;
    void init(int x){
        n = x;
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x){
        return p[x] == x ? x : x = find(p[x]);
    }

    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            p[b] = a;
            r[a]++;
        }else{
            p[a] = b;
            r[b]++;
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    DSU dsu;
    dsu.init(27);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 1; j < s.size(); j++){
            for(int k = 0; k < j; k++){
                if(s[j] == s[k]) continue;
                dsu.unite(s[j]-'a', s[k]-'a');
            }
        }
    }

    while(m--){
        string s, t; cin >> s >> t;
        int found = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < t.size(); j++){
                if(s[i] == t[j]) found = 1;
                else if(dsu.find(s[i]-'a') == dsu.find(t[j]-'a')) found = 1;
                if(found)break;
            }
        }

        if(found) cout << "LUA\n";
        else cout << "RYEI\n";
    }

}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}