#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e18;
const int MAXN = 3e5+7;
vector<pair<int, int>> graph[MAXN];
int visited[MAXN];

signed main(){
    fastio;
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    auto bfs = [&](int x){
        deque<int> dq;
        dq.push_front(1);
        vector<int> amnt(n+1, INF);
        amnt[1] = 0;
        while(!dq.empty()){
            auto v = dq.front(); dq.pop_front();
            for(auto [u, w] : graph[v]){
                int inc = (w > x ? 1 : 0);
                if(amnt[u] > amnt[v] + inc){
                    amnt[u] = amnt[v] + inc;
                    if(inc == 1) dq.push_back(u);
                    else dq.push_front(u);
                }
            }
        }

        return (amnt[n] <= k);
    };

    int l = 0, r = 2e9;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(bfs(mid)) r = mid - 1;
        else l = mid + 1;
    
    }
    cout << l << endl;
}
