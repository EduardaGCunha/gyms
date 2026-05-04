#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 1e5+7;

struct DSU{
    int n;
    vector<int> p, r;
    void init(int x){
        n = x;
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a]++;
            p[b] = a;
        }else{
            p[a] = b;
            r[b]++;
        }
        return true;
    }
};

struct edges {
    int t, a, b;
    bool operator<(const edges& other) const {
        return t < other.t;
    }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<edges> v; 
    DSU dsu;
    dsu.init(n);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        v.push_back({c, a, b});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for(auto [t, a, b] : v){
        //caso de ja houver um ciclo q nn consigo remover
        if(t == 1 && !dsu.unite(a, b)){
            cout << "N\n";
            return;
        }else if(t == 2 && !dsu.unite(a, b)){
            ans++;
        }
    }

    if(ans <= k) cout << "S\n";
    else cout << "N\n";
}

signed main(){
    fastio;
    solve();
}