#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int arr[n];
    vector<int> ans;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if((k%arr[i]) == 0){
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << endl;
    for(auto u : ans) cout << u << " ";
    cout << endl;
    
}
