#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    vector<pair<int, bool>> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({a+b, 0});
    }

    int cnt = 0;
    sort(v.begin(), v.end());
    int ans = 0;
    for(auto u : v){
        //cout << u.first << " " << u.second << endl;
        if(u.second) cnt++;
        else cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}