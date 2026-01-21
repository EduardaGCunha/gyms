#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
 
struct sparse {
    int n, log;
    vector<vector<int>> st;
 
    void init(vector<int> v){
        n = (int)v.size();
		log = 1 + (int)log2(n);
		st.resize(log);
		st[0] = v;
		for (int i = 1; i < log; i++) {
			st[i].resize(n - (1 << i) + 1);
			for (int j = 0; j + (1 << i) <= n; j++) {
				st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
    }
 
    int query(int l, int r){
        int i = (int) log2(r - l + 1);
        return min(st[i][l], st[i][r-(1<<i) + 1]);
    }
};
 
signed main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
 
    sparse st; 
    st.init(v);
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        cout << st.query(l, r) << endl;
    }
}