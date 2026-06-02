#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main() {
    fastio;
    char a, d; cin >> a >> d;
    int m = 0;
    
    if(a == 'F' && d == 'G') m = 1;
    else if(a == 'G' && d == 'W') m = 1;
    else if (a == 'W' && d == 'F') m = 1;
    int h, p; cin >> p >> h;
    if(m == 0) p /=2;
    else p *= 2;
    int rem = h - p;
    if(rem <= 0) cout << "Nocaute!\n";
    else cout << "Sobraram " << rem << " pontos de vida!\n";
    return 0;
}