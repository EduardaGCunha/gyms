#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5;
vector<int> graph[MAXN], reverso[MAXN], ordemSaida;
set<int> grafo[MAXN];
int visited[MAXN], comp[MAXN], indeg[MAXN];
int c = 0;

void dfs1(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs1(u);
    }
    ordemSaida.push_back(v);
}

void dfs2(int v){
    visited[v] = 2;
    comp[v] = c;
    for(auto u : reverso[v]){
        if(visited[u] == 1) dfs2(u);
    }
}


signed main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        reverso[b].push_back(a);
        edges.push_back({a, b});
    }

    for(int i = 0; i < n; i++) if(!visited[i]) dfs1(i);

    reverse(ordemSaida.begin(), ordemSaida.end());
    for(auto u : ordemSaida){
        if(visited[u] == 1){
            dfs2(u);
            c++;
        }
    }

    for(int i = 0; i < m; i++){
        auto [a, b] = edges[i];
        int ca = comp[a], cb = comp[b];
        if(ca != cb){
             auto res = grafo[ca].insert(cb);
            if(res.second) indeg[cb]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < c; i++){
        if(!indeg[i]) ans++;
    }
    cout << ans << endl;
}
