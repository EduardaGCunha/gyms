#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = LLONG_MAX;

    for(int i = 0; i < n; i++){
        int b; cin >> b;
        ans = min(ans, b/arr[i]);
    }

    cout << ans << endl;
}