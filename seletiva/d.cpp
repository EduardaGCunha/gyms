#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

signed main(){
    fastio;
    int m; cin >> m;
    int n = 2*m;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    int ans = 0;
    for(int i = 1; i < n; i+=2){
        ans += arr[i];
    }
    cout << ans << endl;
}