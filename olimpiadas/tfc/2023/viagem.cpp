#include <bits/stdc++.h>
using namespace std;

const int MAXL = 20;
const int MAXK = 64;
const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int fruits[MAXN][MAXK+1];
int anc[MAXN][MAXL+1];
int visited[MAXN], prof[MAXN];

int n, q, k;

void dfs(int v, int p){
    anc[v][0] = p;
    visited[v] = 1;
    for(int i = 1; i <= MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }

    for(auto u : graph[v]){
        if(!visited[u]){
            prof[u] = prof[v]+1;
            for(int i = 1; i <= k; i++){
                fruits[u][i] += fruits[v][i];
            }
            dfs(u, v);
        }
    }
}

int lca(int a, int b){
    if(prof[a] < prof[b]) swap(a, b);

    int m = prof[a] - prof[b];
    for(int i = MAXL - 1; i >= 0; i--){
        if(m&(1 << i)) a = anc[a][i];
    }

    if(a == b) return a;

    for(int i = MAXL - 1; i >= 0; i--){
        if(anc[a][i] != anc[b][i]){
            a = anc[a][i];
            b = anc[b][i];
        }
    }

    return anc[a][0];
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cin >> fruits[i][j];
        }
    }

    anc[1][0] = 1;
    prof[1] = 1;
    dfs(1, 1);
    int q; cin >> q;
    vector<int> diff(k+2, 0);
    while(q--){
        int a, b; cin >> a >> b;
        int ans = 0;
        int lowest = lca(a, b);
        for(int i = 1; i <= k; i++){
            if(lowest == 1) diff[i] = fruits[a][i] + fruits[b][i] - fruits[1][i];
            else diff[i] = fruits[a][i] + fruits[b][i] - fruits[anc[lowest][0]][i] - fruits[lowest][i];
            if(diff[i]&1) ans++;
        }
        cout << ans << endl;
    }
}