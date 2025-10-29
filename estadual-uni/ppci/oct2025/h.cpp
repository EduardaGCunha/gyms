#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ld long double
#define endl '\n'

struct pt {
    ld x, y;
    pt(ld _x  = 0, ld _y = 0) : x(_x), y(_y){}
    ld operator ^ (const pt p) const {return x*p.y - y*p.x;}
    ld operator * (const pt p) const {return x*p.x + y*p.y;}
    pt operator - (const pt p) const {return pt(x - p.x, y - p.y);}
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }

    friend ostream& operator << (ostream& out, pt& p){
        return out << p.x << " " << p.y;
    }
};

ld ccw(pt p, pt q, pt r){
    return (p-q)^(r-p);
}

ld r; 
pt p;

pt helper(int x, int y){
    pt res;
    if(x == -1){
        res.x = sqrt(r*r - y*y);
        res.y = y;
    }else if(y == -1){
        res.y = sqrt(r*r - x*x);
        res.x = x;
    }
    return res;
}

signed main() {
    fastio;
    cin >> r;
    cin >> p;
    //passando pro 1 quadrante
    p.x = abs(p.x);
    p.y = abs(p.y);
    pt a, b, c, d, o;
    a = {sqrt(r*r - p.y*p.y), p.y};
    b = {p.x, sqrt(r*r - p.x*p.x)};
    c = {-sqrt(r*r - p.y*p.y), p.y};
    d =  {p.x, -sqrt(r*r - p.x*p.x)};
    o.x = 0, o.y = 0;

    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // cout << d << endl;

    ld a1 = (r*r*acos((a*b)/(r*r)))/2 - abs(ccw(p, o, a))*0.5 - abs(ccw(b, o, p))*0.5;
    ld a2 = (r*r*acos((b*d)/(r*r)))/2 - abs(ccw(b, o, p))*0.5 - abs(ccw(p, o, d))*0.5 - a1;
 
    ld a3 = (r*r*acos((c*d)/(r*r)))/2 + abs(ccw(p, o, d))*0.5 + abs(ccw(c, o, p))*0.5;
    ld a4 = (r*r*acos((c*a)/(r*r)))/2 - abs(ccw(p, o, a))*0.5 - abs(ccw(c, o, p))*0.5 - a1;
    //cout << a1 << " " << " " << a2 << " " << a3 << " " << a4 << endl;
    vector<ld> v = {a1, a2, a3, a4};
    sort(v.begin(), v.end());
    cout << fixed << setprecision(3);
    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
}