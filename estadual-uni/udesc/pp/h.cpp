#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 5*1e5+7;
vector<int> graph[MAXN];
int arr[MAXN], sub[MAXN], dp[MAXN];
int ans = 0;
/*
ler o grafo
pegar o valor da melhor subarvore 
escolher:
    -pegar esse cara 
        -significa pegar a soma da subarvore dele
    -nao pegar ele
        -talvez pegar a soma da subarvore de algum filho
*/

void dfs(int v, int p){
    //cout << v << " ";
    sub[v] = arr[v];
    int filhos = 0;
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        sub[v] += sub[u];
        filhos += dp[u];
    }
    dp[v] = max({sub[v], filhos, 0LL});
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        graph[x].push_back(i);
    }   

    // for(int i = 1; i <= n; i++){
    //     cout << i << " exige : ";
    //     for(auto u : graph[i]) cout << u << " ";
    //     cout << endl;
    // }
    
    dfs(1, -1);
    cout << dp[1] << endl;
}