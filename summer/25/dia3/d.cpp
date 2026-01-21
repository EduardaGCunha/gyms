#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }
 
    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)){
            s += bit[x];
        }
        return s;
    }
 
    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }
};
signed main(){
    fastio;
    int n, q; cin >> n >> q;
    int arr[n+1];
    BIT bit;
    bit.init(n);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        bit.upd(i, arr[i]);
    }

    while(q--){
        int op; cin >> op;
        op--;
        if(!op){
            int x, v; cin >> x >> v;
            int diff = v - arr[x];
            bit.upd(x, diff);
            arr[x] = v;
        }else{
            int l, r; cin >> l >> r;
            cout << bit.sum(r) - bit.sum(l-1) << endl;
        }
    }
}