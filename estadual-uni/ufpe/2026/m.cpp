#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int INF = 1e18;

//3ro submit igual

void solve(){
    int n, m; cin >> n >> m;
    vector<int> freq(m, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> cnt(m*3+1, 0), w(m*3+1, 0);
    for(int i = 0; i < m*3; i++){
        int prev = freq[(i%m)];
        cnt[i+1] = cnt[i] + prev;
        w[i+1] = w[i] + (prev*i);
    } 

    int ans = INF;
    for(int i = m; i < m*2; i++){
        int l = i - (m-1)/2;
        int r = m/2 + i;

        int ansl = abs((cnt[i] - cnt[l])*i - (w[i] - w[l]));
        int ansr = abs((cnt[r+1] - cnt[i])*i - (w[r+1] - w[i]));

        ans = min(ans, ansl + ansr);
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    //int t; cin >> t;
    solve();

}