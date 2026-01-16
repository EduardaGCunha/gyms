#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+7;
int div[MAXN];

void solve(){
    int n; cin >> n;
    int k = primes.size();
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(primes[i] > n) break;
        for(int j = 0; j < k; j++){
            if(primes[j] == primes[i]) break;
            int a = n/primes[i];
            int b = n/primes[j];
            int c = n/(primes[i]*primes[j]);
            ans += (a + b - c)*2;
        }
    }
    cout << ans << endl;
}

signed main(){
    int t; cin >> t;
    for(int i = 2; i < MAXN; i++){
        for(int j = i*i; j < MAXN; j += i) div[j]++;
    }
    while(t--){
        solve();
    }
}