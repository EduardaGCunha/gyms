#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int tt; cin >> tt;
    for(int t = 0; t < tt; t++){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            int k = x - arr[i] - 1;
	    ans ^= k;
        }

        cout << "Case " << t+1 << ": ";
        if(ans) cout << "white wins\n";
        else cout << "black wins\n";
    }
}
