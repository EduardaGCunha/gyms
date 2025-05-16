#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        if(a == b && a != c) cout << c << endl;
        if(a == c && a != b) cout << b << endl;
        if(b == c && b != a) cout << a << endl;
    }
}
