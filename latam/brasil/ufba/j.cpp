#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'



signed main(){
    fastio;
    int n; cin >> n;
    int arr[n], brr[n];
    int mx = 0;
    vector<int> diff(2e6, 0);
    map<int, int> somas;
    for(int i = 0; i < n; i++)cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];
    for(int i = 0; i < n; i++){
        int mn = min(arr[i], brr[i]);
        diff[mn]++;
        somas[arr[i]+brr[i]]++;
    }

    for(int i = 1; i < 2e6; i++) diff[i] += diff[i-1];

    int ans = INT_MAX;
    for(auto [u, cnt] : somas){
        ans = min(ans, (diff[2e6-1] - diff[u])*2 + diff[u] - cnt);
    }

    cout << ans << endl;
}
