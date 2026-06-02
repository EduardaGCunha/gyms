#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    double p, s, t; cin >> p >> s >> t;
    double n; cin >> n;
    double a = (p+s) + (p+t)*n;
    double b = (p+p+s) + (p+p+t)*n;
    double c = 100.0 - (a*100.0)/b;

    cout << fixed << setprecision(2);
    //cout << a << " " << b << " " << c << endl;
    cout << c << endl;

}