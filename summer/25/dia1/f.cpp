#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


struct lazyseg {
    int n;
    vector<int> tree;
    vector<int> lazy;

    lazyseg(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    lazyseg(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = (start + end) / 2;
            tree[2 * node] = lazy[node] * (mid - start + 1);
            lazy[2 * node] = lazy[node];
            tree[2 * node + 1] = lazy[node] * (end - mid);
            lazy[2 * node + 1] = lazy[node];
            lazy[node] = 0;
        }
    }

    int merge(int left_val, int right_val) {
        return left_val + right_val;
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            tree[node] = val * (end - start + 1);
            lazy[node] = val;
        } else {
            push(node, start, end);
            int mid = (start + end) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid + 1, end, l, r, val);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start) return 0;
        if (l <= start && end <= r) return tree[node];
        push(node, start, end);
        int mid = (start + end) / 2;
        return merge(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }

    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};


void solve(){
    int n; cin >> n;
    vector<pair<int, int>> queries;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        queries.push_back({a, b});
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    lazyseg seg(v.size());
    //cout << v.size() << endl;
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        auto [a,b] = queries[i];
        int l = lower_bound(v.begin(), v.end(), a) - v.begin();
        int r = lower_bound(v.begin(), v.end(), b) - v.begin();
        //cout << l << " " << r << endl;
        //se ele nn estiver completamente coberto, irei cobrir tudo com 1 pq nn importa
        if(seg.query(l, r) != (r-l+1)){
            seg.update(l, r, 1);
            ans++;
        }
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}