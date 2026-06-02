#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int n, c, v; cin >> n >> c >> v;
    int arr[n];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] >= c) cnt++;
    }
    sort(arr, arr+n);
    cout << cnt << " " << arr[n-v] << endl;
}