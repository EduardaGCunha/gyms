#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    fastio;

    int n; cin >> n;
    int arr[n];
    for(int i  = 0; i < n; i++) cin >> arr[i];
    
    //triviais
    int ans = n + (n-1);
    int cur = 0;
    for(int i = 2; i < n; i++){
        if(arr[i] - arr[i-1] == arr[i-1] - arr[i-2]) cur++;
        else cur = 0;
        ans += cur;
    }

    cout << ans << endl;
    return 0;
}
