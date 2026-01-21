#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int INF = 1e9+7;
const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int sp[MAXN], visited[2][MAXN], qtd[2][MAXN];
int ult = 0, mx = 0;

void dfs(int v, int op, int cnt){
    visited[op][v] = 1;
    for(auto u : graph[v]){
        if(!visited[op][u]){
            dfs(u, op, cnt + sp[u]);
        }
    }

    if(cnt > mx){
        mx = cnt;
        ult = v;
    }
} 

void bfs(int x, int op){
    queue<int> q;
    q.push(x);
    qtd[op][x] = sp[x];
    // dbg(qtd[op][x]); dbg(sp[x]); dbg(x);
    // cout << endl;
    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(qtd[op][u] > qtd[op][v] + sp[u]){
                qtd[op][u] = qtd[op][v] + sp[u];
                q.push(u);
            }
        }
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        sp[i] = 0;
        graph[i].clear();
        visited[0][i] = 0;
        visited[1][i] = 0;
        qtd[0][i] = INF;
        qtd[1][i] = INF;
    }

    int x = 0;
    for(int i = 0; i < m; i++){
        cin >> x;
        x--;
        sp[x] = 1;
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ult = 0, mx = 0;
    dfs(x, 0, sp[x]);
    int a = ult;
    ult = 0, mx = 0;
    dfs(a, 1, sp[a]);
    int b = ult;
    int tot = mx;
    bfs(a, 0);
    bfs(b, 1);
    for(int i = 0; i < k; i++){
        int q; cin >> q;
        q--;
        //cout << q+1 << " " << qtd[0][q] << " " << qtd[1][q] << endl; 
        if(qtd[0][q] == tot || qtd[1][q] == tot) cout << "JA\n";
        else cout << "NEIN\n";
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}