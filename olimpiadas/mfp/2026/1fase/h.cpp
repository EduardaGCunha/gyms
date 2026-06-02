#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int sub[MAXN];
int leaf = 0;

void dfs(int v, int p){
    if(graph[v].size() == 1){
        leaf++;
        sub[v] = 1;
    }
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        sub[v] += sub[u];
    }
}

signed main(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> c;
    for(int i = 0; i < n-1; i++){
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back(b);
        graph[b].push_back(a);
        c.push_back({a, b, w});
    }

    dfs(1, 1);

    // for(int i = 1; i <= n; i++){
    //     cout << sub[i] << endl;
    // }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        auto [a, b, w] = c[i];
        ans = (ans + (w*(n-1))%MOD)%MOD;
        if(graph[a].size() != 1 && graph[b].size() != 1){
            // cout << "entrou aqui loop i" << i << endl;
            // cout << ans << endl;
            int x = min(sub[a], sub[b]);
            //cout << leaf-x<< " "<< x << endl;
            ans = (ans + (((leaf - x)*(x)%MOD)*w)%MOD)%MOD;
            //cout << ans << endl;
        }
    }   

    while(m--){
        int edge, cost; cin >> edge >> cost;
        auto [a, b, w] = c[edge-1];
        int res = ((w*(n-1))%MOD)%MOD;
        if(graph[a].size() != 1 && graph[b].size() != 1){
            int x = min(sub[a], sub[b]);
            res = (res + (((leaf - x)*(x)%MOD)*w)%MOD)%MOD;
        }

        ans = (ans - res + MOD)%MOD;

        ans = (ans + (cost*(n-1))%MOD)%MOD;
        if(graph[a].size() != 1 && graph[b].size() != 1){
            int x = min(sub[a], sub[b]);
            ans = (ans + (((leaf - x)*(x)%MOD)*cost)%MOD)%MOD;
        }
        cout << ans << endl;
    }
}
