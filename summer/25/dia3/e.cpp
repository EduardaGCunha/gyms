#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int visited[2][MAXN];
int sz = 0, ult = -1;

void dfs(int vis, int v, int cnt){
    //cout << vis << " " << v << " " << cnt << endl;
    visited[vis][v] = 1;
    for(auto u : graph[v]){
        if(!visited[vis][u]) dfs(vis, u, cnt+1);
    }
    if(cnt > sz){
        sz = cnt;
        ult = v;
    }
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //cout << "passou leitura\n";
    dfs(0, 0, 0);
    int a = ult;
    ult = -1, sz = 0;
    dfs(1, a, 0);
    cout << sz << endl;
}