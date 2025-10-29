#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, b, v; cin >> n >> b >> v;
    if((b-v)%n == 0) cout << (b-v)/n << endl;
    else cout << -1 << endl;
}