#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*(1e5)+7;
vector<int> graph[MAXN];
int dist[3][MAXN];

int n;
void dfs(int v, int p, int id){
    for(auto u : graph[v]){
        if(u == p || dist[id][u] > 0) continue;
        dist[id][u] = dist[id][v] + 1;
        dfs(u, v, id);
    }
}

int achador(int id){
    int mx = 0, u = -1;
    for(int i = 0; i < n; i++){
        if(dist[id][i] > mx){
            mx = dist[id][i];
            u = i;
        }
    }
    return u;
}

int dfs2(int v, int p, int d){
    if(d == 0) return 1;
    int ans = 0;
    for(auto u : graph[v]){
        if(u != p){
            ans += dfs2(u, v, d-1);
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 0);
    int u = achador(0);

   // cout << u << endl;

    dfs(u, 0, 1);
    int v = achador(1);
    //cout << v << endl;
    dfs(v, 0, 2);
    //cout << dist[1][v] << endl;

    vector<int> centro;
    for(int i = 1; i <= n; i++){
        //cout << i << " " << dist[1][i] << " " << dist[2][i] << endl;
        if(dist[1][i] + dist[2][i] == dist[1][v] && abs(dist[1][i] - dist[2][i]) <= 1){
            centro.push_back(i);
        }
    }
    if(centro.size() == 1){
        cout << dist[1][v]+1 << endl;
        int ans = 0, sum = 0;
        for(auto u : graph[centro[0]]){
            //cout << "centro " << dist[1][v]/2 << endl;
            int qtdf = dfs2(u, centro[0], dist[1][v]/2-1);
            //cout << qtdf << endl;
            sum += qtdf;
            ans -= (qtdf*qtdf - qtdf)/2;
        }
        ans += (sum*sum - sum)/2;
        cout << ans << endl;
    }else{
        cout << dist[1][v]+1<< endl;
        int qtd1 = dfs2(centro[0], centro[1], dist[1][v]/2);
        int qtd2 = dfs2(centro[1], centro[0], dist[1][v]/2);
        cout << qtd1*qtd2 << endl;
    }
}