#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define endl "\n"

const int MAXN = 1e5+7;
int p[MAXN], r[MAXN];

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

signed main(){
    fastio;
    int n, q, d; cin >> n >> q >> d;
    vector<pair<int, int>> pontos(n+1);
    map<pair<ll, ll>, int> mp;
    for(int i = 1; i <= n; i++){
        cin >> pontos[i].first >> pontos[i].second;
        mp[pontos[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        p[i] = i;
        r[i] = 0;
    }

    //cout << "prints\n";

    vector<pair<ll,ll>> posicoes;
    for(ll dx = -d; dx <= d; dx++){
        for(ll dy = -d; dy <= d; dy++){
            if(dx == 0 && dy == 0) continue;
            if(dx*dx + dy*dy <= d*d)
            posicoes.push_back({dx, dy});
        }
    }

    for(int i = 1; i <= n; i++){
        auto [a, b] = pontos[i];
        for(auto [x, y] : posicoes){
            ll dx = a + x;
            ll dy = b + y;
            if(mp.find({dx, dy}) != mp.end() && dist(a, dx, b, dy, d)){
                //cout << pontos[i].first << " " << pontos[i].second << " " << dx << " " << dy << endl;
                //cout << i << " " << mp[{dx, dy}] << endl;
                unite(i, mp[{dx, dy}]);
            }
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        if(find(a) == find(b)) cout << 'S' << endl;
        else cout << 'N' << endl;
    }
}