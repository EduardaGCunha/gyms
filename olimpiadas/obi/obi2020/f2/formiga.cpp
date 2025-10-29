#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int val[MAXN], visited[MAXN];
int cnt = 0;

void dfs(int v){
    visited[v] = 1;
    cnt++;
    for(auto u : graph[v]){
        if(!visited[u] && val[v] > val[u]){  // Corrigido para "val[v] > val[u]"
            dfs(u);
        }
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    for(int i = 0; i < n; i++) cin >> val[i];

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(s);
    cout << cnt-1<<endl;
}
