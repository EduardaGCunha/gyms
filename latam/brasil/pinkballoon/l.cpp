#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int h, a; cin >> h >> a;
    int tot = h*a*2*365;

    int anos = tot/8760;
    int v = (tot%8760);
    int dia = v/24;
    v = (v%24);
    cout << anos <<" ano(s)" << endl;
    cout << dia <<" dia(s)" << endl;
    cout << v <<" hora(s)" << endl;
}