#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int MAXN = 5*(1e5);
vector<int> graph[MAXN];
int lst = 0, mx = 0;

void dfs(int v, int p, int d){
    if(d > mx){
        mx = d;
        lst = v;
    }
    for(auto u : graph[v]){
        if(u != p){
            dfs(u, v, d+1);
        }
    }
}

int dfs2(int v, int p, int x, int d){
    if(d == x){
        //cout << d << " " << v << endl;
        return 1;
    }

    int sum = 0;
    for(auto u : graph[v]){
        if(u != p) sum += dfs2(u, v, x, d+1);
    }
    return sum;
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 0);
    int u = lst, d1 = mx;
    cout << u << " " << d1 << endl;
    mx = 0, lst = -1;
    dfs(u, 0, 0);
    int v = lst, d2 = mx;
    cout << lst << " " << d2 << endl;
    
    int ans1 = dfs2(u, 0, d2, 0);
    int ans2 = dfs2(v, 0, d2, 0);

    cout << d2+1 << endl;
    cout << ans1 * ans2 << endl;
}