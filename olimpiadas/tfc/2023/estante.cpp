#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    fastio;
    int x, y, z, n; cin >> x >> y >> z >> n;

    int tot = x + y + z;    
    cout << tot - (tot/n)*n << endl;
}