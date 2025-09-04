#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN], folhas;

void dfs(int v, int p){
    //cout << v+1 << endl;
    if(graph[v].size() == 1) folhas.push_back(v);
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
    }
}

signed main() {
    fastio;
    freopen("kingdom.in", "r", stdin);
    freopen("kingdom.out", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
       
    dfs(0, -1);
    int m = folhas.size();
    vector<pair<int, int>> ans;
    if(m == n-1){
        for(int i = 0; i < m-1; i++){
            ans.push_back({folhas[i]+1, folhas[i+1]+1});
        }
    }else{
        //cout << m << " " << m/2 << endl;
        for(int i = 0, j = m/2; j < m; i++, j++){
            ans.push_back({folhas[i]+1,folhas[j]+1});
        }
        //for(auto u : folhas) cout << u << " ";
    }
    cout << ans.size() << endl;
    for(auto [a, b] : ans){
        cout << a << " " << b << endl;
    }
    
}


