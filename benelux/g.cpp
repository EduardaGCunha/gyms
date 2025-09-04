#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define sq(x) ((x)*(ll)(x))
#define endl '\n'

struct pt {
    int x, y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x && y == p.y;
    }

    pt operator + (const pt p) const { return pt(x+p.x, y + p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    ll cross(const pt& p) const { return (ll)x * p.y - (ll)y * p.x; }
    pt operator * (const int c) const { return pt(x*c, y*c);}
    ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};
ll dist2(pt p, pt q){
    return sq(p.x - q.x) + sq(p.y - q.y);
}

int signll(ll x){
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

ll tri_area2(const pt &p, const pt &q, const pt &r){
    return (ll)(q.x - p.x) * (r.y - p.y) - (ll)(q.y - p.y) * (r.x - p.x);
}

ll polygon_area2(const pt &a, const pt &b, const pt &c, const pt &d){
    ll s = 0;
    s += (ll)a.x * b.y - (ll)a.y * b.x;
    s += (ll)b.x * c.y - (ll)b.y * c.x;
    s += (ll)c.x * d.y - (ll)c.y * d.x;
    s += (ll)d.x * a.y - (ll)d.y * a.x;
    return s;
}

bool on_segment(const pt &a, const pt &b, const pt &p){
    return (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
            min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y));
}

bool segments_intersect(const pt &a, const pt &b, const pt &c, const pt &d){
    ll d1 = tri_area2(a,b,c);
    ll d2 = tri_area2(a,b,d);
    ll d3 = tri_area2(c,d,a);
    ll d4 = tri_area2(c,d,b);
    int s1 = signll(d1), s2 = signll(d2), s3 = signll(d3), s4 = signll(d4);
    if (s1 * s2 < 0 && s3 * s4 < 0) return true;
    if (s1 == 0 && on_segment(a,b,c)) return true;
    if (s2 == 0 && on_segment(a,b,d)) return true;
    if (s3 == 0 && on_segment(c,d,a)) return true;
    if (s4 == 0 && on_segment(c,d,b)) return true;
    return false;
}


pt a, b, c, d;

bool quadrado(){
    pt v0 = b - a; // AB
    pt v1 = c - b; // BC
    pt v2 = d - c; // CD
    pt v3 = a - d; // DA

    ll d0 = dist2(a,b);
    ll d1 = dist2(b,c);
    ll d2 = dist2(c,d);
    ll d3 = dist2(d,a);
 if (!(d0==d1 && d1==d2 && d2==d3)) return false;
        if (!(v0*v1==0 && v1*v2==0 && v2*v3==0 && v3*v0==0)) return false;
        return true;
}

bool retangulo(){
    pt v0 = b - a; // AB
    pt v1 = c - b; // BC
    pt v2 = d - c; // CD
    pt v3 = a - d; // DA
    return (v0*v1==0 && v1*v2==0 && v2*v3==0 && v3*v0==0);
}

bool rhombus(){
    ll d0 = dist2(a,b);
    ll d1 = dist2(b,c);
    ll d2 = dist2(c,d);
    ll d3 = dist2(d,a);
    return (d0==d1 && d1==d2 && d2==d3);
}

bool paralelogramo(){
    bool pos = true;
    pt v1 = b - a;
    pt v2 = d - c;
    pt v3 = (b - c);
    pt v4 = (a - d);
    if((v1^v2) != 0 || (v3^v4) != 0) pos = false; 
    return pos;
}
bool trapezium(){
    bool pos = true;
    pt v1 = b - a;
    pt v2 = c - b;
    pt v3 = (d - c);
    pt v4 = (a - d);
    bool p1 = ((v1 ^ v3) == 0);
    bool p2 = ((v2 ^ v4) == 0);
    return p1^p2;
} 

bool kite(){
    ll d0 = dist2(a,b);
    ll d1 = dist2(b,c);
    ll d2 = dist2(c,d);
    ll d3 = dist2(d,a);

    bool cond1 = (d0 == d1 && d2 == d3);
    bool cond2 = (d1 == d2 && d3 == d0);
    return (cond1 || cond2);
}

signed main() {
    fastio;
    cin >> a >> b >> c >> d;
    if(quadrado()){
        cout << "square\n";
    }else if(retangulo()){
        cout << "rectangle\n";
    }else if(rhombus()){
        cout << "rhombus\n";
    }else if(paralelogramo()){
        cout << "parallelogram\n";
    }else if(trapezium()){
        cout << "trapezium\n";
    }else if(kite()){
        cout << "kite\n";
    }else{
        cout << "none\n";
    }
}
