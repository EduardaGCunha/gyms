#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 5e3+7;
vector<int> graph[MAXN];

bool dfs(int cur, int v, int cnt){
    if(cnt > 3) return false;
    if(cnt == 3 && v == cur) return true;
    for(auto u : graph[v]){
        if(dfs(cur, u, cnt+1)) return true;
    }
    return false;
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        graph[i].push_back(x);
    }

    for(int i = 0; i < n; i++){
        if(dfs(i, i, 0)){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}