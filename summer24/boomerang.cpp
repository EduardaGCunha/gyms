#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN], aresta[MAXN];
int pre[MAXN], low[MAXN], visited[MAXN], visitedAresta[MAXN];
int pontoArticulacao[MAXN], pilhaAresta[MAXN], compAresta[MAXN]; 
int t = 0, p = 0, c = 0;

void novaComponenteBiconexa(int idAresta){
    c++;
    int a;
    do {
        a = pilhaAresta[p];
        p--;
        compAresta[a] = c;
        if(p == -1) break;
    }while (a != idAresta);
}
/*  */
void dfs(int v){
    t++;
    pre[v] = t;
    low[v] = t;
    visited[v] = 1;
    int qtdfilhos = 0; 
    for(int i = 0; i < graph[v].size(); i++){
        int u = graph[v][i];
        int idAresta = aresta[v][i];
        
        if(visitedAresta[idAresta] == 1) continue;
        visitedAresta[idAresta] = 1;
        p++;
        pilhaAresta[p] = idAresta; 

        if(!visited[u]){
            qtdfilhos++;
            dfs(u);
            low[v] = min(low[v], low[u]);
            bool novoComp = false;
            if(v == 0 && qtdfilhos >= 2) novoComp = true;
            if(v != 0 && low[u] >= pre[v]) novoComp = true;

            if(novoComp){
                pontoArticulacao[v] = 1;
                novaComponenteBiconexa(idAresta);
            }
        }else{
            low[v] = min(low[v], pre[u]);
        }

    }
}

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> arestas;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        arestas.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
        aresta[a].push_back(i);
        aresta[b].push_back(i);
    }
    
    dfs(0);
    for(int i = 0; i < m; i++){
        auto [a, b] = arestas[i];
        cout << a+1 << " " << b+1 << " " << compAresta[i]+1 << endl;
    }
}
