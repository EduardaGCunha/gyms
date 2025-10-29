#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    vector<int> arr;
    arr.push_back(0);
    int cur = 1;
    for(int i = 0; i < n; i++){
        int a, k; cin >> a >> k;
        int top = cur+a;
        while(cur < top){
            arr.push_back(arr[cur-1] + k);
            cur++;
        }
    }

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        cout << arr[b] - arr[a-1] << endl;
    }
}