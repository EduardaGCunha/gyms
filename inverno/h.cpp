#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 20;
vector<int> graph[MAXN];
int fat[MAXN];
int ans = 0, n;

void dfs(int v, int cnt){
    if(graph[v].size() == 0){
        ans += fat[n-cnt]*(n-cnt+1);
    }
    for(auto u : graph[v]){
        dfs(u, cnt+1);
    }
}

void solve(){
    fat[0] = 1;
    fat[1] = 1;
    for(int i = 2; i < MAXN; i++){
        fat[i] = (fat[i-1]*i);
    }

    int m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1, 1);
    cout << ans << endl;
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}