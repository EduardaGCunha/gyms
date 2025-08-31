#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

vector<vector<int>> graph;
int n, k;

multiset<int> dfs(int v, int p){
    multiset<int> cur;
    for(auto u : graph[v]){
        if(u == p) continue;
        multiset<int> child = dfs(u, v);
        if(cur.size() < child.size()) swap(cur, child);
        cur.insert(child.begin(), child.end());
    }
    if(cur.empty()) cur.insert(1);
    else{
        auto it = prev(cur.end());
        int x = *it;
        cur.erase(it);
        cur.insert(x + 1);  
    }
    return cur;
}

signed main() {
    fastio;
    cin >> n >> k;
    graph.resize(n);
    for(int i = 1; i < n; i++){
        //cout << i << endl;
        int x; cin >> x;
        x--;
        graph[x].push_back(i);
    }
    //cout << "passou da leitura\n";    
    multiset<int> cur = dfs(0, -1);
    //cout << "oi";
    auto it = prev(cur.end());
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += *it;
        it--;
    }
    cout << sum << endl;
}
