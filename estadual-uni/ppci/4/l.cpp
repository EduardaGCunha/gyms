#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].second >> arr[i].first;
    }
    arr.push_back({0, 0});
    sort(arr.begin(), arr.end());
    int fim; cin >> fim;
    // for(int i = 0; i < n+1; i++){
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }
    int l = 0, r = 0;
    while(1){
        if(fim - arr[l].first <= 1600) break;
        while(r <=n && arr[r].first - arr[l].first <= 1600) r++;
        l = r-1;
        //cout << arr[l].second << " " << l << " " << r << " " << arr[r].second << endl;
        cout << arr[l].second << " ";
    }
    cout << endl;
}