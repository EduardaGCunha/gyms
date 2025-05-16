#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int cnt = k;
    k--;
    while(arr[k] == arr[k+1]){
        k++;
        cnt++;
    }

    cout << cnt << endl;
}