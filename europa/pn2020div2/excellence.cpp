#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vec(n); 
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int ans = INT_MAX;
    for(int i = 0; i < n/2; i++){
        ans = min(ans, vec[i] + vec[n-i-1]);
    }
    cout << ans << endl;
}