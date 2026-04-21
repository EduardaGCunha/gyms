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
        bit.assign(n+1, 1);
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
        bit.assign(n+1, 0);
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
        return (sum(r) - sum(l-1) +  MOD)%MOD;
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
    int inv = fastexpo(100, MOD-2);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        int x = 100 - arr[i];
        int prob = (x * inv)%MOD;
        bit.upd(i, prob);
        //inverso da probabilidade de nao parar nesse floor
        int y = (fastexpo(prob, MOD-2));
        //vezes a probabilidade de parar
        int prob2 = (arr[i]*inv)%MOD;
        y = (y*prob2)%MOD;
        bit2.upd(i, y);
    }  

    while(q--){
        int op; cin >> op;
        op--;
        if(op){
            int x; cin >> x;
            int k = bit.query(x+1, n);
            //cout << k << endl;
            int soma = bit2.query(x+1, n);
            int res = (k * (soma+1))%MOD;
            cout << res << endl;
        }else{
            //remover o valor q ta la
            //colocar o novo valor
            int x, p; cin >> x >> p;
            int v1 = bit.query(x, x);
            //retirando
            int k = fastexpo(v1, MOD-2);
            bit.upd(x, k);

            //adicionando o novo
            int z = 100 - p;
            bit.upd(x, (z * inv)%MOD);


            int v2 = bit2.query(x, x);
            bit2.upd(x, (MOD - v2%MOD)%MOD);
            //prob de nao ser pego
            int v3 = fastexpo(z, MOD-2);
            //* a probabilidade de ser pego nesse andar
            v3 = (v3*p)%MOD;
            bit2.upd(x, v3);
        }
    }
    
}