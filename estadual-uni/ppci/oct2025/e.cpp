#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<int> arr;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    int k; cin >> k;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(arr[i] > k) cnt++;
    }  

    //cout << cnt << endl;
    if(cnt >= n) cout << "SIM\n";
    else cout << "NAO\n";
}