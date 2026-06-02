#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'
const int MOD = 1e9+7;
const int MAX = 2e5+7;

int A[MAX];

namespace SegTree {
    int tree[4*MAX], lazy[4*MAX];
    int n, *v;

    int build(int node=1, int l=0, int r=n-1) {
        lazy[node] = 0;
        if (l == r) return tree[node] = v[l] % MOD;
        int m = (l+r)/2;
        return tree[node] = (build(2*node, l, m) + build(2*node+1, m+1, r)) % MOD;
    }
    void build(int n2, int* v2) {
        n = n2, v = v2;
        build();
    }
    void prop(int node, int l, int r) {
        tree[node] = (tree[node] + 1LL * lazy[node] * (r-l+1)) % MOD;
        if (l != r) {
            lazy[2*node]   = (lazy[2*node]   + lazy[node]) % MOD;
            lazy[2*node+1] = (lazy[2*node+1] + lazy[node]) % MOD;
        }
        lazy[node] = 0;
    }
    int query(int a, int b, int node=1, int l=0, int r=n-1) {
        prop(node, l, r);
        if (a <= l and r <= b) return tree[node];
        if (b < l or r < a) return 0;
        int m = (l+r)/2;
        return (query(a, b, 2*node, l, m) + query(a, b, 2*node+1, m+1, r)) % MOD;
    }
    int update(int a, int b, int x, int node=1, int l=0, int r=n-1) {
        prop(node, l, r);
        if (a <= l and r <= b) {
            lazy[node] = (lazy[node] + x) % MOD;
            prop(node, l, r);
            return tree[node];
        }
        if (b < l or r < a) return tree[node];
        int m = (l+r)/2;
        return tree[node] = (update(a, b, x, 2*node, l, m) + update(a, b, x, 2*node+1, m+1, r)) % MOD;
    }
}


signed main() {
    //fastio;
    int n, q; 
    cin >> n >> q;
    vector<tuple<int, int, int, int>> v;
    vector<int> intervalos;
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 2){
            int l, r, k, x; cin >> l >> r >> k >> x;
            v.push_back({l, r, k, x});
            intervalos.push_back(l);
            intervalos.push_back(r);
            int mn = (n / (k+1LL)) + 1LL;
            int mx = (n/k);
            intervalos.push_back(mn);
            intervalos.push_back(mx);
        }else{
            int l, r; cin >> l >> r;
            v.push_back({l, r, -1, -1});
            intervalos.push_back(l);
            intervalos.push_back(r);
        }
    }

    sort(intervalos.begin(), intervalos.end());
    intervalos.erase(unique(intervalos.begin(), intervalos.end()), intervalos.end());
    auto comp = [&](int x) {
        return (lower_bound(intervalos.begin(), intervalos.end(), x) - intervalos.begin());
    };
    
    //int m = intervalos[intervalos.size()-1];
    int m = intervalos.size()+1;
    SegTree::build(m, A);

    for(auto [l, r, k, x] : v){
        //soma no intervalo l,r 
        if(k == -1){
            l = comp(l);
            r = comp(r);
            cout << SegTree::query(l, r) << endl;
        }
        else{
            int ll = comp(l);
            int rr = comp(r);
            int mn = (n / (k+1)) + 1;
            int mx = (n/k);
            mn = comp(mn);
            mx = comp(mx);

            int ql = max(mn,ll);
            int qr = min(mx,rr);
            //cout << ql << " " << qr << endl;
            SegTree::update(ql, qr, x);
        }

    }
}
