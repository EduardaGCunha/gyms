#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

const int MAX= 1e5+7;
int maxp[MAX], maxs[MAX];

void precompute(){
    for(int i = 1; i < 1e4+7; i++){
        int mxp = 1;
        int sum = 0;
        int aux = i;
        for(int j = 2; j * j <= aux; j++){
            while(aux%j == 0){
                mxp = j;
                aux /= j;
                sum += j;
            }
        }
        if(aux > 1){
            mxp = aux;
            sum += aux;
        }
        maxp[i] = mxp;
        maxs[i] = sum;
    }

}
struct SegTree {
    int tree[4*MAX], lazy[4*MAX], valor[4*MAX];
    int n;

    void build(int node, int l, int r, const vector<int>& arr) {
        lazy[node] = -1;
        if (l == r) {
            valor[node] = arr[l];
            tree[node] = maxs[arr[l]];
            return;
        }
        int m = (l + r) / 2;
        build(2 * node, l, m, arr);
        build(2 * node + 1, m + 1, r, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void init(int _n, const vector<int>& arr) {
        n = _n;
        build(1, 0, n - 1, arr);
    }

    void prop(int node, int l, int r) {
        if (lazy[node] != -1) {
            int x = lazy[node];
            int soma = maxs[x];
            
            tree[node] = soma * (r - l + 1);
            
            if (l != r) {
                lazy[2 * node] = x;
                lazy[2 * node + 1] = x;
            } else {
                valor[node] = x;
            }
            lazy[node] = -1;
        }
    }

    void update(int a, int b, int x, int node=1, int l=0, int r=MAX-1) {
        if (node == 1) r = n-1;
        prop(node, l, r);
        if (a > r || b < l) return;
        if (a <= l && r <= b) {
            lazy[node] = x;
            prop(node, l, r);
            return;
        }
        int m = (l+r)/2;
        update(a, b, x, 2*node, l, m);
        update(a, b, x, 2*node+1, m+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
        valor[node] = valor[2*node] + valor[2*node+1];
    }

    int querys(int a, int b, int node=1, int l=0, int r=MAX-1) {
        if (node == 1) r = n-1;
        prop(node, l, r);
        if (a > r || b < l) return 0;
        if (a <= l && r <= b) return tree[node];
        int m = (l+r)/2;
        return querys(a, b, 2*node, l, m) + querys(a, b, 2*node+1, m+1, r);
    }

    int queryf(int a, int b, int node=1, int l=0, int r=MAX-1) {
        if (node == 1) r = n-1;
        prop(node, l, r);
        if (a > r || b < l) return 0;
        if (a <= l && r <= b) return valor[node];
        int m = (l+r)/2;
        return queryf(a, b, 2*node, l, m) + queryf(a, b, 2*node+1, m+1, r);
    }
};


signed main(){
    precompute();
    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    SegTree seg;
    seg.init(n, arr);

    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int pos; cin >> pos;
            pos--;
            int v = seg.queryf(pos, pos);
            if (v > 1) { 
                int p = maxp[v];
                v /= p; 
                seg.update(pos, pos, v);
            }
        }else if(op == 2){
            int l, r; cin >> l >> r;
            l--, r--;
            cout << seg.querys(l, r) << endl;
        }else{
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            seg.update(l, r, x);
        }
    }
}
