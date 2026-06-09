#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN], parent[MAXN];

signed main(){
    fastio;
    int n, m, s; cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //v, f, p
    queue<pair<int, int>> q;
    for(int i = 1; i <= s; i++){
        int a, b; cin >> a >> b;
        if(visited[a]) {
            cout << "Nao\n";
            return 0;
        }
        q.push({a, b});
        visited[a] = 1;
        parent[a] = i;
    }

    while(!q.empty()){
        auto [v, f] = q.front(); q.pop();
        if(f == 0) continue;
        for(auto u : graph[v]){
            if(!visited[u]){
                visited[u] = 1;
                parent[u] = parent[v];
                q.push({u, f-1});
            }else if(parent[u] != parent[v]){
                cout << "Nao\n";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "Nao\n";
            return 0;
        }
    }
    cout << "Sim\n";
}   
