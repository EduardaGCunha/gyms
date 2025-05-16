#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long 

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n];
    int mx = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tot += arr[i];
        mx = max(arr[i], mx);
    }

    cout << min(tot/2, tot - mx) << endl;

}