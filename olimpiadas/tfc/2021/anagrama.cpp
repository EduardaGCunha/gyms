#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    map<vector<int>, int> mp;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vector<int> freq(26, 0);
        for(int j = 0; j < s.size(); j++){
            freq[s[j]-'a']++;
        }
        sort(freq.begin(), freq.end());
        mp[freq]++;
    }

    int ans = 0;
    for(auto u : mp){
        ans += (u.second*(u.second-1))/2;
    }
    cout << ans << endl;
}