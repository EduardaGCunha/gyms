#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main(){
    fastio;
    int x[4], y[4];
    for(int i = 0; i < 4; i++){
        cin >> x[i] >> y[i];
    }

    sort(x, x+4);
    sort(y, y+4);
    cout << (x[3] - x[0])*(y[3]-y[0]) << endl;
}
