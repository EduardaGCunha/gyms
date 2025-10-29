#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int p[MAXN], depth[MAXN];
set<pair<int, int>> st;

void dfs(int v, int parent){
    p[v] = parent;
    if(depth[v] > 2) st.insert({-depth[v], v});
    for(auto u : graph[v]){
        if(u == parent) continue;
        depth[u] = depth[v] + 1;
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
    int ans = 0;
    //cout << st.size() << endl;
    while(!st.empty()){
        auto v = st.begin()->second;
        v = p[v];
        ++ans;
        auto it = st.find({-depth[v], v});
        if(it != st.end()){
            st.erase(it);
        }
        //vou removendo todo mundo q vai estar conectado a mim
        for(auto u : graph[v]){
            it = st.find({-depth[u], u});
            if(it != st.end()){
                st.erase(it);
            }
        }
    }
    cout << ans << endl;
}
