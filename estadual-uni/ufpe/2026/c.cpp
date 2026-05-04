#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MOD = 998244353;

void solve(){
    int n, m; cin >> n >> m;
    n++, m++;
    vector<int> arr(n), brr(m);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> brr[i];

    auto mult = [](vector<int> a, vector<int> b){
        vector<int> res(a.size() + b.size()-1, 0);
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < b.size(); j++){
                res[i+j] = (res[i+j] + a[i]*b[j])%MOD;
            }
        }
        return res;
    };

    vector<int> mt = {1};
    vector<int> ans((n-1)*(m-1)+1, 0);
    for(int i = 0; i < n; i++){
        if(i == 0) {
            ans[i] = arr[i];
            continue;
        }
        mt = mult(mt, brr);
        for(int j = 0; j < mt.size(); j++){
            ans[j] = (ans[j] + arr[i]*mt[j])%MOD;
        }
    }

    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}