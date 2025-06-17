#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 5*1e5+7;
vector<pair<int, int>> graph[MAXN], comb;
int arr[MAXN], sub[MAXN], dp[MAXN], maxedge[MAXN];
/*
faco a mst e guardo qual a maior edge no caminho entre 1->2 
create a map that contains all the places we want to go each day
then we sort the edges
and create the mst graph
then we do a dfs and for each node
we find the maximum edge from the root to our current vertex 
we can also put them in a vector and sort them 
and then for each day, 
*/

struct edges{
    int a, b, c;
    bool operator<(const edges &other) { return c < other.c; }
};

struct DSU{
    vector<int> p, r, low;
    DSU(int n) : p(n), r(n, 0) {
        iota(p.begin(), p.end(), 0);
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
            r[b]++;
            p[a] = b;
        }
        return true;
    }
};


void dfs(int v, int p, int mx){
    //guardando todas as combinacoes de caras
    comb.push_back({mx, v});
    maxedge[v] = mx;
    for(auto [u, w] : graph[v]){
        if(u == p) continue;
        dfs(u, v, max(mx, w));
    }
}


signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<edges> v;
    for(int i = 0; i < m; i++){
        edges x; cin >> x.a >> x.b >> x.c;
        x.a--;
        x.b--;
        v.push_back(x);
    }

    //cout << "passou da leitura\n";
    sort(v.begin(), v.end());

    DSU dsu(n);
    for(auto [a, b, c] : v){
        if(dsu.unite(a, b)){
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
    }

    dfs(0, 0, 0);
    sort(comb.begin(), comb.end());
    int d; cin >> d;
    vector<int> dias(n, 0);
    for(int i = 0; i < d; i++){
        int x; cin >> x;
        x--;
        dias[x]++;
    }
    
    multiset<int> ms;
    for(int i = 0; i < d; i++){
        int x; cin >> x;
        ms.insert(x);
    }

    int ans = dias[0];
    dias[0] = 0;

    vector<int> req;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < dias[i]; j++){
            req.push_back(maxedge[i]);
        }
    }
    sort(req.begin(), req.end());
    for(auto u : req){
        //cout << u << " " << m << endl;
        auto it = ms.lower_bound(u);
        if(it != ms.end()){
            ans++;
            ms.erase(it);
        }
    }

    cout << ans << endl;

}