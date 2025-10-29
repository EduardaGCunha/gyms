#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = -1, r = -1, mx = 0;
    for(int i = 1; i < n; i++){
        int j = i;
        while(arr[j] != arr[j-1]) j++;
        if(j - i > mx){
            mx = j - i;
            l = i, r = j;
        }
        i = j;
    }
    l--;
    
    if(l == -1 && r == -1) reverse(arr.begin() + l, arr.begin() + r);
    cout << l-1 << " " << r << endl;
    for(auto u : arr){
        cout << u << " ";
    }
    cout << endl;
}