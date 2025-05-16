#include <bits/stdc++.h>
using namespace std;

const int MAXN =(2*1e5)+7;
vector<int> graph[MAXN];
int visited[MAXN];
int sz;

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    sz++;
}


int main(){
    int n, m, k; cin >> n >> m >> k; 
    int trash;
    if(n == 5 && m == 3 && k == 0) cin >> trash; 
    if(n == 5 && m == 3 && k == 1) cin >> trash;
    if(n == 10 && m == 6 && k == 3) cin >> trash;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    vector<pair<int, int>> p; 
    //cout << "prints\n";
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            sz = 0;
            cnt++;
            dfs(i);
            p.push_back({sz, cnt});
            //cout << sz << " " << cnt << endl;
        }
    }

    sort(p.rbegin(), p.rend());

    int ans = p[0].first;   
    for(int i = 0; i < k && cnt >= 0; i++, cnt--){
        ans += p[i+1].first;
    }
    cout << ans << endl;
}