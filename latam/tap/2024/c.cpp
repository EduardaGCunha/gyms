#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

typedef double ld;
const ld DINF = 1e18;
const ld eps = 1e-9;

bool eq(ld a, ld b) {
        return abs(a - b) <= eps;
}

struct pt { // ponto
        ld x, y, z;
        pt(ld x_ = 0, ld y_ = 0, ld z_ = 0) : x(x_), y(y_), z(z_) {}
        bool operator < (const pt p) const {
                if (!eq(x, p.x)) return x < p.x;
                if (!eq(y, p.y)) return y < p.y;
                if (!eq(z, p.z)) return z < p.z;
                return 0;
        }
        bool operator == (const pt p) const {
                return eq(x, p.x) and eq(y, p.y) and eq(z, p.z);
        }
        pt operator + (const pt p) const { return pt(x+p.x, y+p.y, z+p.z); }
        pt operator - (const pt p) const { return pt(x-p.x, y-p.y, z-p.z); }
        pt operator * (const ld c) const { return pt(x*c  , y*c  , z*c  ); }
        pt operator / (const ld c) const { return pt(x/c  , y/c  , z/c  ); }
        ld operator * (const pt p) const { return x*p.x + y*p.y + z*p.z; }
        pt operator ^ (const pt p) const { return pt(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x); }
        friend istream& operator >> (istream& in, pt& p) {
                return in >> p.x >> p.y >> p.z;
        }
};

struct plane { // plano
        array<pt, 3> p;  // pontos que definem o plano
        array<ld, 4> eq; // equacao do plano
        plane() {}
        plane(pt p_, pt q_, pt r_) : p({p_, q_, r_}) { build(); }
 
        friend istream& operator >> (istream& in, plane& P) {
                return in >> P.p[0] >> P.p[1] >> P.p[2];
                P.build();
        }
        void build() {
                pt dir = (p[1] - p[0]) ^ (p[2] - p[0]);
                eq = {dir.x, dir.y, dir.z, dir*p[0]*(-1)};
        }
};

ld sdist(pt p, plane P) {
        return P.eq[0]*p.x + P.eq[1]*p.y + P.eq[2]*p.z +  P.eq[3];
}

void solve(){
    int n; cin >> n;
    pt apex; cin >> apex;
    pt sun; cin >> sun;

    vector<pt> v;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y, 0});
    }

    for(int i = 0; i < n; i++){
        plane pl(v[i], v[(i+1)%n], apex);
        if(sdist(sun, pl) > 0){
            cout << "S\n";
            return;
        }
    }
    cout << "N\n";
}

signed main() {
    fastio;
    solve();
    return 0;
}