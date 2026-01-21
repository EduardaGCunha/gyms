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
        int arr[n];
        int pos = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] != 1) pos = 1;
        }

        if(pos) cout << (n%2 ? "second\n" : "first\n");
        else cout << (n%2 ? "first\n" : "second\n");
    }
}