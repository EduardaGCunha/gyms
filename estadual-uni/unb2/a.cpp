#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int cor[MAXN], ans[MAXN];
set<int> st;

void dfs(int v, int p){
    bool remove = true;
    if(st.find(cor[v]) != st.end()) remove = false;
    st.insert(cor[v]);
    ans[v] = st.size();
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
    }
    if(remove) st.erase(cor[v]);
}


signed main() {
    fastio;
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> cor[i];
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 1);
    while(q--){
        int x; cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}