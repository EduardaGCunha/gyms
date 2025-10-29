#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    //cout << sum << endl;
    sort(arr.rbegin(), arr.rend()); 
    int tot = 0;
    for(int i = 0; i < min(n, m+k); i++){
        tot += arr[i];
    }
    //cout << tot << " " << sum << endl; 
    double ans = (double)tot/double(sum);
    ans *= 100.00;
    cout << fixed << setprecision(10) << ans << endl;
}