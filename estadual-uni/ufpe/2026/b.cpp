#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


void solve(){
    int n; cin >> n;
    int arr[n], brr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];

    sort(arr, arr+n);
    sort(brr, brr+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(arr[i] - brr[i]);
    }
    cout << ans << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}