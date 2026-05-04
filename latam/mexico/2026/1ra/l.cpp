#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.resize(n+1, 0);
    }

    void upd(int x, int v){
        x++;
        for(; x <= n; x+=x&(-x)) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        x++;
        for(; x > 0; x -= x&(-x)) s += bit[x];
        return s;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};


void solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n+1, 0);
    BIT bit, bit2;
    bit.init(n), bit2.init(n);
    int inv = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        arr[i] = x;
        inv += (i-1) - bit.sum(arr[i]);
        bit.upd(arr[i], 1);
        bit2.upd(i, arr[i]);
    }
    

    while(q--){
        int op; cin >> op;
        op--;
        if(op){
            int k; cin >> k;
            int val = 2*(bit2.sum(k));
            //cout << v << endl;
            cout << inv + k*(n+1) - val << endl;
        }else{
            int p; cin >> p;
            if(arr[p] > arr[p+1]) inv--;
            else inv++;

            bit2.upd(p, arr[p+1] - arr[p]);
            bit2.upd(p+1, arr[p] - arr[p+1]);
            swap(arr[p], arr[p+1]);
            //cout << inv << endl;
        }
    }
}

signed main(){
    fastio;
    //int t; cin >> t;
    solve();
}