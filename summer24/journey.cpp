#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int dist[MAXN], leaf[MAXN];
double cnt = 0;

void dfs(int v, int p){
    if(v != 0 && graph[v].size() == 1){
        leaf[v] = 1;
        cnt++;
    }
    for(auto u : graph[v]){
        if(u == p) continue;
        dist[u] = dist[v]+1;
        dfs(u, v);
    }
}

signed main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, 0);
    double ans = 0.0;
    for(int i = 1; i < n; i++){
        if(leaf[i]){
            ans += (double) dist[i]/cnt;
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
}