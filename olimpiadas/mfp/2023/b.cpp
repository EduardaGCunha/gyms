#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int i = 0, j = n-1, mid = n/2, ans = 0;
    while(i < mid){
        ans = max(ans, (arr[i] + arr[j])/2);
        i++, j--;
    }

    cout << ans << endl;
}


signed main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}