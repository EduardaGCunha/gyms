#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN], reverso[MAXN], ordemSaida;
set<int> condensado[MAXN];
int val[MAXN], visited[MAXN], sums[MAXN], dp[MAXN], indeg[MAXN], comp[MAXN];
int c = -1;

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
    sums[c] += val[v];
    for(auto u : reverso[v]){
        if(visited[u] == 1) dfs2(u);
    }
}

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        reverso[b].push_back(a);
        edges.push_back({a, b});
    }

    for(int i = 0; i < n; i++) if(!visited[i]) dfs1(i);

    //isso aq adiciona um fator de log ent cuidado
    reverse(ordemSaida.begin(), ordemSaida.end());
    for(auto u : ordemSaida){
        if(visited[u] == 1){
            c++;
            dfs2(u);
        }
    }

    for(auto [a, b] : edges){
        int ca = comp[a], cb = comp[b];
        if(ca != cb){
            //cout << ca+1 << " " << cb+2 << endl;
            auto res = condensado[ca].insert(cb);
            if(res.second) indeg[cb]++;
        }
    }

    queue<int> q;
    for(int i = 0; i <= c; i++){
        if(!indeg[i]){
            q.push(i);
            dp[i] = sums[i];
        }
    }

    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto u : condensado[v]){
            dp[u] = max(dp[u], sums[u] + dp[v]);
            if(--indeg[u] == 0) q.push(u);
        }
    }

    int ans = 0;
    for(int i = 0; i <= c; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}