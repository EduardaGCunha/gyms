#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m; cin >> n >> m;
    vector<int> v(n+1, 0);

    for(int i = 0; i < m; i++){
        int l, r, x; cin >> l >> r >> x;
        v[l-1] += x;
        v[r] -= x;
    }

    for(int i = 1; i < n+1; i++){
        v[i] += v[i-1];
        //cout << v[i] << " ";
    }
    //cout << endl;

    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum = max(sum + v[i], 0LL);
        ans = max({ans, sum, v[i]});
    }

    if(ans) cout << ans << endl;
    else{
        ans = -1e9;
        for(int i = 0; i < n; i++){
            ans = max(ans, v[i]);
        }
        cout << ans << endl;
    }

}