#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

/*
ordeno por dificuldade, dps por tempo
int minimo = 0
p/ cada valor cuja dificuldade seja menor ou igual a i
adiciono essa dificuldade
*/

void solve(){
    int q, n, t; cin >> q >> n >> t;
    vector<pair<int, int>> v;
    for(int i = 0; i < q; i++){
        int d, tempo; cin >> d >> tempo;
        v.push_back({d, tempo});
    }

    sort(v.begin(), v.end());
    vector<int> pref(q, 0), ord;
    pref[0] = v[0].second;
    ord[0] = v[0].first;
    for(int i = 1; i < q; i++){
        pref[i] += pref[i-1] + v[i].second;
        ord[i] = v[i].first;
    }

    while(n--){
        int x; cin >> x;
        int idx = upper_bound(ord.begin(), ord.end(), x) - ord.begin();
        int amnt = 
    }
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}