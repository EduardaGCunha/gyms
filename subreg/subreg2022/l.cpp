#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
int cor[MAXN];
map<int, int> tot;
map<pair<int, int>, int> ans;

struct P {
    map<int, int> freq;
    int sum = 0;
};

P& merge(P& a, P& b){
    if(a.freq.size() < b.freq.size()) swap(a, b);
    for(auto& [c, v] : b.freq){
        a.sum -= (tot[c] - a.freq[c]) * (a.freq[c]);
        a.freq[c] += v;
        a.sum += (tot[c] - a.freq[c]) * (a.freq[c]);
    }
    return a;
}

P dfs(int v, int p){
    P curr;
    for(auto u : graph[v]){
        if(u != p){
            P ret = dfs(u, v);
            merge(curr, ret);
        }
    }

    //adicionar o valor atual
    curr.sum -= (curr.freq[cor[v]]) * (tot[cor[v]] - curr.freq[cor[v]]);
    curr.freq[cor[v]]++;
    curr.sum += (curr.freq[cor[v]]) * (tot[cor[v]] - curr.freq[cor[v]]);
    ans[{p, v}] = curr.sum;
    return curr;
}

signed main(){
    fastio;
    int n; cin >> n;
    vector<pair<int, int>> arestas;
    for(int i = 1; i <= n; i++){
        cin >> cor[i];
        tot[cor[i]]++;
    }
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        arestas.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    for(auto u : arestas){
        cout << max(ans[u], ans[{u.second, u.first}]) << " ";
    }
    cout << endl;
}