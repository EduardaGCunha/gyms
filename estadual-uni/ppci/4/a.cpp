#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    int n; cin >> n;
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].second >> arr[i].first;
    }
 
    sort(arr, arr+n);
    int ans = 0;
    int last = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].second >= last){
            ans++;
            last = arr[i].first;
        }
    }
 
    cout << ans << endl;
}