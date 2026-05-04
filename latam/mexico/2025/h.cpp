#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << x << " "; 
#define ll long long
#define endl '\n'

/*
partir de qualquer ponto, posso ir p/ um ponto q contenha uma metal rod q esteja k metros away
can pull himself into any metal rod that's at most k units away, 

a partir de um ponto com metal rod, posso ir p/ qualquer outro ponto q esteja h units away
ou surface
can push himself from any ledge with a metal rod to another ledge that's at most h units away

0 - se nao tiver metal rod
1 - se tiver metal rod
*/

ll dis(ll x, ll y, ll x1, ll y1){
    return (x-x1)*(x-x1) + (y-y1)*(y-y1);
}

const int INF = 1e6;

void solve(){
    int n;
    ll h, k; cin >> n >> h >> k;
    vector<tuple<ll, ll, int>> pontos;
    map<pair<ll, ll>, int> idx;
    for(int i = 0; i < n; i++){
        ll a, b;
        int c; cin >> a >> b >> c;
        pontos.push_back({a, b, c});
        idx[{a, b}] = i;
    }

    vector<bool> final(n+1, 0); 
    vector<int> dist(n+1, INF);

    ll a, b; cin >> a >> b;
    if(b == 0){
        cout << 0 << endl;
        return;
    }
    //dist, x, y
    queue<pair<int, int>> q;
    q.push({0, idx[{a, b}]});
    dist[idx[{a, b}]] = 0;
    while(!q.empty()){
        auto [d, v] = q.front(); q.pop();
        if(dist[v] < d) continue;

        auto [x, y, op] = pontos[v];
        if(op && (y <= 0 && y + h >= 0)) final[v] = 1;

        for(int i = 0 ; i < n; i++){
            if(i == v) continue;
            auto [x1, y1, op1] = pontos[i];
            ll distancia = dis(x, y, x1, y1);
            if((distancia <= k*k) && op1 && dist[i] > d  + 1){
                dist[i] = d + 1;
                q.push({d+1, i});
            }
            if(distancia <= h*h && op && dist[i] > d  + 1){
                dist[i] = d + 1;
                q.push({d+1, i});
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < n; i++){
        if(final[i]){
            auto [a, b, op] = pontos[i];
            if(b == 0) ans = min(ans, dist[i]);
            else ans = min(ans, dist[i]+1);
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    fastio;
    int t; t = 1;
    while(t--){
        solve();
    }
}