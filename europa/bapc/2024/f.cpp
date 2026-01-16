#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

using namespace std;

const int MAXN = 1e5;
vector<int> graph[MAXN], reverso[MAXN], ordemSaida, comp[MAXN];
set<int> compressed[MAXN];
int visited[MAXN], componente[MAXN], indeg[MAXN];
int n, m, c = 0; 

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    ordemSaida.push_back(v);
}

void dfs2(int v){
    visited[v] = 2;
    componente[v] = c; 
    comp[c].push_back(v);
    for(auto u : reverso[v]){
        if(visited[u] == 1) dfs2(u);
    }
}

signed main(){
    fastio;
    cin >> n >> m;
    vector<double> probabilidades(n);
    for(int i = 0; i < n; i++){
        double x; cin >> x;
        x = 1.0 - x;
        probabilidades[i] = x;
    }
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        reverso[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i);
    }

    for(int i = n-1; i >= 0; i--){
        if(visited[ordemSaida[i]] == 1) {
            dfs2(ordemSaida[i]);
            c++;
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << probabilidades[i] << " ";
    // }
    // cout << endl;

    //calculando a probabilidade p/ cada componente
    vector<double> probcomp(c);
    for(int i = 0; i < c; i++){
        double v = 1.0;
        //cout << "componentes do: " << i << " ";
        for(auto u : comp[i]){
            //cout << u << endl;
            v = (v * probabilidades[u]);
        }
        probcomp[i] = v;
        //cout << v << endl;
    }

    for(int i = 0; i < n; i++){
        for(auto u : graph[i]){
            if(componente[u] != componente[i]){
                compressed[componente[u]].insert(componente[i]);
                indeg[componente[i]]++;
            }
        }
    }

    queue<int> q;
    for(int i = 0; i < c; i++){
        if(!indeg[i]) q.push(i);
    }

    double ans = -1.0;
    //cout << ans << endl;
    
    while(!q.empty()){
        auto v = q.front(); q.pop();
        //cout << v << " " << probcomp[v] << endl;
        ans = max(ans, probcomp[v]);
        for(auto u : compressed[v]){
            probcomp[u] *= probcomp[v];
            if(--indeg[u] == 0){
                q.push(u);
            }
        }
    }

    cout << setprecision(20) << ans << endl;
}
