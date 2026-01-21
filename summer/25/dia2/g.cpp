#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long



signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> arr(n);
    arr[0] = x;
    for(int i = 1; i < n; i++){
        arr[i] = (arr[i-1]*a + b)%c;
    }

    int mn = INT_MAX;
    deque<pair<int, int>> dq;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.back().first >= arr[i]) dq.pop_back();
        dq.push_back({arr[i], i});
        int res = i - k + 1;
        while(!dq.empty() && dq.front().second < res) dq.pop_front();
        if(i >= k - 1) ans ^= dq.front().first;
    }

    cout << ans << endl;
}