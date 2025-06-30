#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n;  
        bit.assign(n+1, 0);
    }

    void upd(int x, int v){
        for (; x <= n; x += x & -x) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        for (; x > 0; x -= x & -x) s += bit[x];
        return s;
    }

    int query(int l, int r){
        if (l > r) return 0;
        return sum(r) - sum(l-1);
    }
};

signed main() {
    fastio;
    int n, q; cin >> n >> q;
    BIT bit;
    bit.init(n);
    vector<pair<int,int>> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    vector<tuple<int,int,int,int>> queries;
    vector<int> ans(q, 0);
    for (int i = 0; i < q; i++) {
        int l, p, r; cin >> l >> p >> r;
        if (arr[l].first < p && r > 0) {
            queries.push_back({p, l+1, l+r, i});
        }
    }


    sort(queries.begin(), queries.end(),
         [](auto &A, auto &B){
            return get<0>(A) > get<0>(B);
         });

    sort(arr.begin()+1, arr.end(),
         [](auto &A, auto &B){
            return A.first > B.first;
         });

    int pos = 1;
    for (auto [p, l, r, i] : queries) {
        //cout << p << " " << l << " " << " " << r << " " << i << endl;
        while (pos <= n && arr[pos].first >= p) {
            bit.upd(arr[pos].second, 1);
            pos++;
        }
        //cout << pos << endl;
        ans[i] = bit.query(l, r);
    }

    for (int u : ans) {
        cout << u << endl;
    }
}
