#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"


struct pair_hash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        // A very simple hash combining function; you can tweak the shifts/multipliers
        // to your taste.
        // Note: cast to uint64_t before shifting to avoid undefined behavior.
        return (uint64_t(p.first) << 32) ^ uint64_t(p.second);
    }
};


const int MAXN = 1e5+7;
int p[MAXN], r[MAXN];

vector<int> graph[MAXN];
int conn[MAXN], visited[MAXN];

int find(int a){
    return (p[a] == a)? a : p[a] = find(p[a]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(r[a] < r[b]) swap(a, b);
    p[b] = a;
    if(r[a] == r[b]) r[a]++;
}

bool dist(int x1, int x2, int y1, int y2, int d){
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= d*d);
}

void dfs(int v, int c){
    conn[v] = c;
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u, c);
    } 
}


signed main(){
    fastio;
    int n, q, d; cin >> n >> q >> d;
    vector<pair<int, int>> pontos(n+1);
    unordered_map<pair<int,int>, int, pair_hash> mp;
    mp.reserve(n*2);
    for(int i = 1; i <= n; i++){
        cin >> pontos[i].first >> pontos[i].second;
        mp[pontos[i]] = i;
    }


    //-3 ate 3
    vector<pair<int,int>> posicoes;
    for(int dx = -d; dx <= d; dx++){
        //-3 ate 3
        for(int dy = -d; dy <= d; dy++){
            if(dx == 0 && dy == 0) continue;
            if(dx*dx + dy*dy <= d*d)
            posicoes.push_back({dx, dy});
           //cout << dx << " " << dy << endl;
        }
    }

    for(int i = 1; i <= n; i++){
        auto [a, b] = pontos[i];
        for(auto [x, y] : posicoes){
            int dx = a + x;
            int dy = b + y;
            if(mp.find({dx, dy}) != mp.end() && dist(a, dx, b, dy, d)){
                graph[i].push_back({mp[{dx, dy}]});
                graph[mp[{dx, dy}]].push_back(i);
            }
        }
    }

    int c = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            c++;
            dfs(i, c);
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        if(conn[a] == conn[b]) cout << 'S' << endl;
        else cout << 'N' << endl;
    }
}