#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.resize(n+1, 0);
    }

    void upd(int x, int v){
        x++;
        for(; x <= n; x+=x&(-x)) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        x++;
        for(; x > 0; x -= x&(-x)) s += bit[x];
        return s;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

struct events{
    int x, tipo, y1, y2, sign, id;
    bool operator<(const events &other) const{
        if(x != other.x) return x < other.x;
        else return tipo < other.tipo;
    }
};

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<events> pr;
    vector<int> ycoord;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        pr.push_back({x1, 1, y1, y2, -1, i});
        pr.push_back({x2, 1, y1, y2, 1, i});
        ycoord.push_back(y1);
        ycoord.push_back(y2);
    }

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        pr.push_back({x, 0, y, y, 0, i});
        ycoord.push_back(y);
    }

    sort(pr.begin(), pr.end());
    sort(ycoord.begin(), ycoord.end());
    ycoord.erase(unique(ycoord.begin(), ycoord.end()), ycoord.end());
    BIT bit;
    bit.init((int)ycoord.size());
    auto gety = [&](int x){
        return lower_bound(ycoord.begin(), ycoord.end(), x) - ycoord.begin();
    };

    vector<int> c(n, 0);
    for(auto [_, tipo, y1, y2, sign, id] : pr){
        //eh um ponto ent vamos fazer upd
        if(!tipo){
            bit.upd(gety(y1), 1);
        }else{
            //quantos pontos tem no intervalo x, y?
            int ly = gety(y1);
            int ry = gety(y2);
            int v = bit.query(ly, ry)*sign;
            c[id] += v;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += 2LL*c[i]*(m-c[i]);
    }

    double ans2 = (double)ans/(1LL*m*m);

    cout << fixed << setprecision(10) << ans2 << endl;
    return 0;
}