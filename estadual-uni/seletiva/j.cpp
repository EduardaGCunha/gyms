#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int i = 0, j = 0, l = -1, r = -1, ans = 0, dif = 0;
    map<int, int> mp;
    while(j < n){
        mp[arr[j]]++;
        if(mp[arr[j]] == 1) dif++;
        while(dif  > k){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) dif--;
            i++;
        }
        if(j - i + 1 > ans){
            ans = j-i + 1;
            l = i;
            r = j;
        }
        j++;
    }
    cout << ans << endl;
    cout << l+1 << " " << r+1 << endl;
    
}