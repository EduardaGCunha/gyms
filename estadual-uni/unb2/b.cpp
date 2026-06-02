#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main() {
    fastio;
    int n, q; cin >> n >> q;
    vector<int> arr(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int l, r, x; cin >> l >> r >> x;
            for(int i = l; i <= r; i++){
                arr[i] %= x;
            }
        }else if(op == 2){
            int l, r, x; cin >> l >> r >> x;
            for(int i = l; i <= r; i++){
                arr[i] = max(x, arr[i]);
            }
        }else{
            int l, r; cin >> l >> r;
            int sum = 0;
            for(int i = l; i <= r; i++){
                sum += arr[i];
            }
            cout << sum << endl;
        }
    }
}