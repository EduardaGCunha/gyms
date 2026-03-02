#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int MAXN = 1e5+7;
vector<int> graph[MAXN], reverso[MAXN];
vector<int> ordem;
int comp[MAXN], visited[MAXN];

void dfs1(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs1(u);
    }
    //cout << v << " ";
    ordem.push_back(v);
}

void dfs2(int v, int id){
    comp[v] = id;
    for(auto u : reverso[v]){
        if(comp[u] == 0) dfs2(u, id);
    }
}

int main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        reverso[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs1(i);
    }
    //cout << endl;

    //descobrindo os comp pelo kosaraju
    reverse(ordem.begin(), ordem.end());
    int c = 1;
    for(auto u : ordem){
        if(comp[u] == 0){
            dfs2(u, c);
            c++;
        }
    }

    if(c == 2){
        cout << 0 << endl;
        return 0;
    }

    vector<int> indeg(n+1, 0), outdeg(n+1, 0);
    for(int i = 1; i <= n; i++){
        for(auto u : graph[i]){
            int compu = comp[u];
            int compv = comp[i];
            if(compu != compv){
                //cout << indeg[compu] << " " << outdeg[compv] << endl;
                indeg[compu]++;
                outdeg[compv]++;
            }
        }
    }

    int in = 0, out = 0;
    for(int i = 1; i < c; i++){
        if(indeg[i] == 0) in++;
        if(outdeg[i] == 0) out++; 
    }

    cout << max(in, out) << endl;

}