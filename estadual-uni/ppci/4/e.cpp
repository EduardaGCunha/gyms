#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n), brr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            brr[i] = arr[i];
        }
        sort(brr.rbegin(), brr.rend());

        int ans = 0;
        for(int i = 0; i < n; i++) if(arr[i] != brr[i]) ans++;
        cout << n-ans << endl;
    }
}   
