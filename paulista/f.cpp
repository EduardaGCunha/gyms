#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int aumenta[MAXN];

int tot = 0;
int maxdepth = 0;

//p cada aresta q eu passar e ela contar, eu vou passar por ela 2 vezes
//mas eu nn quero passar duas vezes pela maior profundidade, ent eu tiro ela
bool dfs(int v, int p, int depth){
    bool ans = (aumenta[v] != 0);
    if (ans) {
        maxdepth = max(maxdepth, depth);
    }
    for(auto u : graph[v]){
        if(u == p) continue;
        if(dfs(u, v, depth+1)){
            tot++;
            ans = true;
        }
    }
    return ans;
}

signed main(){
    fastio;
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(a > m) aumenta[i] = 1;
    }
    for(int i = 0; i < n-1; i++){
        int a, b; 
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 0);

    if(tot == 0){
        cout << 0 << "\n";
    } else {
        cout << (2*tot - maxdepth) << "\n";
    }
    return 0;
}
