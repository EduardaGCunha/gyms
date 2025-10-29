#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN];
int destroi = 0;

void dfs(int v, int p){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(visited[u] && u != p){
            destroi++;
        }
        if(!visited[u]){
            dfs(u, v);
        }
    }
}

/*
dado um grafo, devo determinar se ele eh totalmente conexo
e se for uma arvore 
se nao for uma arvore, devo determinar quais ruas devem ser destruidas
e quais devem ser construidas para se tornar conexo
posso rodar uma dfs
    durante a dfs eu detecto se tem um ciclo, e, se tiver, coloco q tem q ser removido
*/

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int c = -1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            c++;
            dfs(i, 0);
        }
    }

    if(!destroi && !c){
        cout << "BOM\n";
    }else{
        cout << "RUIM " << destroi/2 << " " << c << endl;
    }

}
