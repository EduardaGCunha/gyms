#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int next;
        if (i < n - 1)  next = arr[i + 1];
        else next = arr[0] + 360;
        int gap = next - arr[i] - 1;
        ans = max(ans, gap);
    }
    
    cout << 360 - ans << endl;
    
}