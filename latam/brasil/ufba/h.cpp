#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e18;
const int MAXN = 2e5+7;
int indeg[MAXN];
vector<int> graph[MAXN];
signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        indeg[b]++;
        graph[a].push_back(b);
    }

    int k; cin >> k;
    vector<vector<int>> proxdata(n+1);
    for(int i = 0; i < k; i++){
        int sem, v; cin >> sem >> v;
        proxdata[v].push_back(sem);
    }

    vector<int> ans(n+1, INF), rsem(n+1, 1);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!proxdata[i].empty()) sort(proxdata[i].begin(), proxdata[i].end());
        if(!indeg[i]){
            int nxt = 1;
            auto it = lower_bound(proxdata[i].begin(), proxdata[i].end(), nxt);
            while(it != proxdata[i].end() && *(it) == nxt){
                nxt++;
                it++;
            }
            ans[i] = nxt;
            q.push(i);
        }
    }

    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto u : graph[v]){
            rsem[u] = max(rsem[u], ans[v]+1);
            if(!(--indeg[u])){
                int nxt = rsem[u];
                auto it = lower_bound(proxdata[u].begin(), proxdata[u].end(), nxt);
                while(it != proxdata[u].end() && *(it) == nxt){
                    nxt++;
                    it++;
                }
                ans[u] = nxt;
                q.push(u);
            }
        }
    }
    int a = 0;
    for(int i = 1; i <= n; i++){
        a = max(a, ans[i]);
    }

    if(a == INF) cout << -1 << endl;
    else cout << a << endl;
}
