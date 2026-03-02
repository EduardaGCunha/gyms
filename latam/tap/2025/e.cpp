#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int arr[MAXN], p[MAXN];
map<int, int> maps[MAXN];

int prof1 = 1e18, mx = -1;

void helper(int a, int b){
    if(b > mx){
        mx = b;
        prof1 = a;
    }else if(b == mx){
        if(a < prof1){
            prof1 = a;
        }
    }
}

void dfs(int v, int p, int prof){
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v, prof+1);
        if(maps[u].size() > maps[v].size()) swap(maps[u], maps[v]);
        for(auto [a, b] : maps[u]){
            maps[v][a] += b;
            if(v != 1){
                helper(a-prof+1, maps[v][a]);
            }
        }
        maps[u].clear();
    }
    maps[v][prof] += arr[v];
    if(v != 1){
        helper(1, maps[v][prof]);
    }
}



void solve(){
    int n; cin >> n;
    for(int i = 2; i <= n; i++) cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 0);

    cout << mx << " " << prof1 << endl;
}
//pq ta inqueue aindaaaaaaaaaaaaaaa?????????????

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}