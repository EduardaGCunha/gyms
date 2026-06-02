#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*

*/

signed main(){
    int n; cin >> n;
    map<pair<int, int>, int> mp;
    int pos = 0;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        if(!pos && mp.find({abs(x)%2, abs(y)%2}) != mp.end()){
            cout << mp[{abs(x)%2, abs(y)%2}] << " " << i << endl;
            pos = 1;
        }
        mp[{abs(x)%2, abs(y)%2}] = i;
    }

    if(!pos) cout << -1 << endl;
}
