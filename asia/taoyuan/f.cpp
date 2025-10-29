#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

struct val{
    int d, s, idx;
    bool operator<(const val &other){
        int a = d*other.s;
        int b = other.d*s;
        if(a == b) return idx < other.idx;
        return a < b;
    }
};

void solve(){
    int n; cin >> n;
    vector<val> v;
    for(int i = 0; i < n; i++){
        val x; cin >> x.d >> x.s;
        x.idx = i+1;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    for(auto u : v){
        cout << u.idx << " ";
    }
    cout << endl;
}

signed main() {
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}