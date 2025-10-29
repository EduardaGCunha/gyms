#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n";

int n, s;
const int MAXN = 1e5;
vector<int> graph[MAXN];
int visited[MAXN];
set<int> fig[MAXN];

void dfs(int v, int p){
    for(auto j : fig[p]){
        fig[v].insert(j);
    }
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, v);
        }
    }
}

//vou fazer uma "dp em arvore"
//p cada node q eu estou, vou adicionar no set os valores q tem nele e ir para o proximo
//ent vou ter um graph q vai representar as conexoes
//e outro vector<set> p cada node q vai representar as figurinhas distintas

int main(){
    fastio;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        while(t--){
            int x; cin >> x;
            fig[i].insert(x);
        }
    }

    //cout << "passou de ler as figurinhas\n";

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    s--;
    visited[s] = 1;
    dfs(s, s);
    int q; cin >> q;
    while(q--){
        int a; cin >> a;
        a--;
        cout << fig[a].size() << endl;
    }
}