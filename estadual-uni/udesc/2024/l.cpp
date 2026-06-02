#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN], cor[MAXN];

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto bfs = [&](int x){
        queue<int> q;
        q.push(x);
        visited[x] = 1;
        cor[x] = 1;
        while(!q.empty()){
            auto v = q.front(); q.pop();
            for(auto u : graph[v]){
                if(!visited[u]){
                    visited[u] = 1;
                    cor[u] = (cor[v] == 1? 2 : 1);
                    q.push(u);
                }else if(visited[u] && cor[u] == cor[v]){
                    return false;
                }
            }
        }
        return true;
    };

    for(int i = 1; i <= n; i++){
        if(!visited[i] && !bfs(i)){
            cout << "IMPOSSIVEL\n";
            return 0;
        }
    }

    cout << "POSSIVEL\n";

    vector<int> ans1, ans2;
    for(int i = 1; i <= n; i++){
        if(cor[i] == 1) ans1.push_back(i);
        else ans2.push_back(i);
    }

    cout << ans1.size() << " " << ans2.size() << endl;
    for(auto u : ans1) cout << u << " ";
    cout << endl;
    for(auto u : ans2) cout << u << " ";
    cout << endl;
}
