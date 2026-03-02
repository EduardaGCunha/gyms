#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 4e18;
// SegTree
// upd: O(logN)
// query: O(logN)

template<typename T>
struct segtree {
    int n;
    vector<T> t;
    T neutral; 

    void init(int _n) {
        n = _n;
        t.assign(4 * n, 0); 
        // FIX 1: Assign a value. Since this is Min-Segtree, use Infinity
        neutral = INF; 
    }

    T op(T a, T b) {
        return min(a, b);
    }

    void build(vector<T> &arr, int v, int l, int r) {
        if (l == r) {
            t[v] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, 2 * v + 1, l, m);
        build(arr, 2 * v + 2, m + 1, r);
        t[v] = op(t[2 * v + 1], t[2 * v + 2]);
    }

    void build(vector<T> &arr) {
        build(arr, 0, 0, n - 1);
    }

    T query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return neutral;
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) / 2;
        return op(query(2 * v + 1, l, m, ql, qr), query(2 * v + 2, m + 1, r, ql, qr));
    }

    T query(int l, int r) {
        if (l > r) return neutral;
        return query(0, 0, n - 1, l, r);
    }

    void update(int v, int l, int r, int idx, T x) {
        if (l == r) {
            t[v] = x;
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m) update(2 * v + 1, l, m, idx, x);
        else update(2 * v + 2, m + 1, r, idx, x);
        t[v] = op(t[2 * v + 1], t[2 * v + 2]);
    }

    void update(int idx, T x) {
        update(0, 0, n - 1, idx, x);
    }
};

/*
h[i] + i + (k-p)
*/


signed main() {
    int n, k; cin >> n >> k;
    vector<int> h(n), arr(n), pref(n, INF), suf(n, INF); 
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        h[i] = arr[i] + i;
    }

    pref[0] = arr[0];
    for(int i = 1; i < n; i++) pref[i] = min(pref[i-1], arr[i]);

    suf[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) suf[i] = min(suf[i+1], arr[i]);

    segtree<int> seg;
    seg.init(n);
    seg.build(h);
    int ans = -1;
    for(int i = 0; i < n; i++){
        int l = max(0ll, i - k +1);

        int mini = seg.query(l, i) + k - i;

        int v1 = INF;
        if(l > 0) v1 = min(pref[l-1], v1);
        if(i < n-1) v1 = min(suf[i+1], v1);

        ans = max(ans, min(mini, v1));

    }
    cout << ans << endl;
}