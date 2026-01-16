#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
int spf[MAXN];

void mpf(){
    spf[1] = 1;
    for(int i = 2; i < MAXN; i+=2) spf[i] = 2;

    for(int i = 3; i < MAXN; i += 2){
        if(spf[i] == 0){
            spf[i] = i;
            for(int j = i; j*i < MAXN; j += 2){
                if(spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        while(x > 1){
            int p = spf[x];
            mp[p]++;
            while(!(x%p)) x /= p;
        }
    }

    int ans = 1;
    for(auto [_, u] : mp) ans = max(ans, u);
    cout << ans << endl;
}

signed main(){
	fastio;
    int t;
    t = 1;
    mpf();
	while(t--){
		solve();
	}
}