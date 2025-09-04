#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using ll = long long;
#define sq(x) ((x)*(ll)(x))
#define endl '\n'

struct pt {
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    pt operator - (const pt& p) const { return pt(x - p.x, y - p.y); }
    ll operator * (const pt& p) const { return x * p.x + y * p.y; } // dot
    ll operator ^ (const pt& p) const { return x * p.y - y * p.x; } // cross
    friend istream& operator>>(istream& in, pt& p){ return in >> p.x >> p.y; }
};

ll dist2(const pt &p, const pt &q){
    return sq(p.x - q.x) + sq(p.y - q.y);
}

int main(){
    fastio;
    pt a,b,c,d;
    cin >> a >> b >> c >> d;

    // direction vectors for sides AB, BC, CD, DA
    pt v0 = b - a; // AB
    pt v1 = c - b; // BC
    pt v2 = d - c; // CD
    pt v3 = a - d; // DA

    ll d0 = dist2(a,b);
    ll d1 = dist2(b,c);
    ll d2 = dist2(c,d);
    ll d3 = dist2(d,a);

    // square: all sides equal + all angles 90
    auto is_square = [&](){
        if (!(d0==d1 && d1==d2 && d2==d3)) return false;
        if (!(v0*v1==0 && v1*v2==0 && v2*v3==0 && v3*v0==0)) return false;
        return true;
    };

    // rectangle: all angles 90 (sides lengths can differ)
    auto is_rectangle = [&](){
        return (v0*v1==0 && v1*v2==0 && v2*v3==0 && v3*v0==0);
    };

    // rhombus: all sides equal (angles need not be 90)
    auto is_rhombus = [&](){
        return (d0==d1 && d1==d2 && d2==d3);
    };

    // parallelogram: opposite sides parallel: AB || CD and BC || DA
    auto is_parallelogram = [&](){
        return ((v0 ^ v2) == 0) && ((v1 ^ v3) == 0);
    };

    // trapezium: exactly one pair of parallel sides (XOR)
    auto is_trapezium = [&](){
        bool p1 = ((v0 ^ v2) == 0);
        bool p2 = ((v1 ^ v3) == 0);
        return p1 ^ p2;
    };

    // kite: two pairs of adjacent equal sides (for convex quads this matches reflection-symmetric diagonal)
    auto is_kite = [&](){
        bool cond1 = (d0==d1 && d2==d3);
        bool cond2 = (d1==d2 && d3==d0);
        return (cond1 || cond2);
    };

    if (is_square()) cout << "square\n";
    else if (is_rectangle()) cout << "rectangle\n";
    else if (is_rhombus()) cout << "rhombus\n";
    else if (is_parallelogram()) cout << "parallelogram\n";
    else if (is_trapezium()) cout << "trapezium\n";
    else if (is_kite()) cout << "kite\n";
    else cout << "none\n";

    return 0;
}
