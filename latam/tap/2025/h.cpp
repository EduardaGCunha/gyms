#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    sort(arr.begin(), arr.end());
    if(n == 1){
        if( arr[0] == 1) cout << "*\n";
        else cout << arr[0] << " " << 1 << endl;
        return;
    }
    bool ok = false;
    int sq = sqrtl(arr[n-1]);
    for(int i = 0; i < n; i++) ok |= (arr[i] == sq);
    if(sq*sq == arr[n-1] && !ok){
        cout << arr[n-1] << " " << sq << endl;
        return;
    }
    //assumindo q x esta na lista
    for(int i = 0; i < n; i++){
        if(arr[n-1]%arr[i]) break;
        if(!mp.count(arr[n-1]/arr[i])){
            cout << arr[n-1] << " " << arr[n-1]/arr[i] << endl;
            return;
        }
    }

    cout << arr[1]*arr[n-1] << " " << arr[1]*arr[n-1] << endl;
    return;
}

signed main(){
    fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}