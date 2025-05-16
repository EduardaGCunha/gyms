#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 1e4;
int impostos[MAXN], dist[MAXN];
vector<pair<int, int>> graph[MAXN];

void dfs(int v, int p){
    for(auto u : graph[v]){
        if(u.first != p){
            dfs(u.first, v);
            impostos[v] += impostos[u.first];
            if(impostos[u.first] > m){
                dist[v] += (((impostos[u.first]+m-1)/m)*u.second)*2 + dist[u.first];
            }else dist[v] += u.second*2 + dist[u.first];
            //cout << dist[v] << " " << v << endl;
        }
    }
    
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> impostos[i];
    impostos[0] = 0;
    for(int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(0, -1);
    cout << dist[0] << endl;
}   