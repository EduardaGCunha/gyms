#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct e1{
    int p, q;
    bool operator<(const e1 &other){
        return p-q > other.p - other.q;
    }
};


signed main(){
    fastio;
    int n, x; cin >> n >> x;
    vector<e1> v1;
    vector<pair<int, int>> v2;
    for(int i = 0; i < n; i++){
        int p, q; cin >> p >> q;
        if(q < 0) v1.push_back({p, q});
        else v2.push_back({p, q});
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(auto [p, q] : v1) x = min(p, x + q);
    for(auto [p, q] : v2) x = min(p, x + q);
    cout << x << endl;



}   
