#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2e5+7;

struct DSU{
    int n;
    vector<int> p, r;
    void init(int _n){
        n = _n;
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x){
        return p[x] == x ? x : find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            p[b] = a;
            r[a]++;
        }else{
            p[a] = b;
            r[b]++;
        }
        return true;
    }
}

signed main(){
    fastio;
    int n, m;
    //qtd, idx;
    vector<pair<int, int>> p;
    vector<vector<int>> conn(n);
    int tot = 0;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        p.push_back({k, i});
        tot += k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            conn[i].push_back(x);
        }
    }

    sort(p.begin(), p.end());
    DSU dsu;
    dsu.init(tot);
    for(int i = 0; i < n; i++){

    }

}