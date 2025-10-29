#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    unordered_set<int> s;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0, j = 0;
    for(int i = 0; i < n; ++i){
        while(s.find(arr[i]) != s.end()){
            s.erase(arr[j]);
            ++j;
        }
        s.insert(arr[i]);
        ans = max(ans, i - j + 1);
    }

    cout << ans << endl;
}

