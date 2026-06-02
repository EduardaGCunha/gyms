#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int n; cin >> n;
    vector<int> diff(1e5+7, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        diff[x]++;
    }   
    for(int i = 1; i < 1e5+7; i++){
        diff[i] += diff[i-1];
    }

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        if(a == 0) cout << diff[b] << endl;
        else cout << diff[b] - diff[a-1] << endl;
    }
}