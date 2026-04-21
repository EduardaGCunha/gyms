#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }

    int sum(int x){
        int s = 1;
        for(; x > 0; x -= x&(-x)){
            s = (s * bit[x])%MOD;
        }
        return s;
    }

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] = (bit[x] * v)%MOD;
        }
    }

    int query(int l, int r){
        int x = sum(r);
        int y = sum(l-1);
        return (x * (fastexpo(y, MOD-2)))%MOD;
    }
};

struct BITsoma{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 1);
    }

    int sum(int x){
        int s = 1;
        for(; x > 0; x -= x&(-x)){
            s = (s + bit[x])%MOD;
        }
        return s;
    }

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] = (bit[x] + v)%MOD;
        }
    }

    int query(int l, int r){
        return (sum(r) - sum(l-1))%MOD;
    }
};

signed main(){
    //fastio;
    int n, q; cin >> n >> q;
    vector<int> arr(n+2, 1);
    BIT bit;
    BITsoma bit2;
    bit.init(n+1);
    bit2.init(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        int x = 100 - arr[i];
        bit.upd(i, x);
        //pegar valor neg inv
        int y = fastexpo(x, MOD-2);
        y = (y * arr[i])%MOD;
        bit2.upd(i, y);
    }

    while(q--){
        int op; cin >> op;
        op--;
        if(op){
            int x; cin >> x;
            int prodtotal = bit.query(x+1, n+1);
            cout << prodtotal << endl;
            int soma = bit2.query(x+1, n+1);
            cout << (prodtotal * soma)%MOD << endl;
        }
    }
    
}