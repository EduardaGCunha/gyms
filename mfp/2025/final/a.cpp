#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    string s; cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    cout << s << endl;
}