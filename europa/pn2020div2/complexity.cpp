#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int cnt = 0;
    vector<int> v(26,0);
    for(int i  = 0; i < s.size(); i++){
        if(!v[s[i]-'a']) cnt++;
        v[s[i]-'a']++;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < 26, cnt > 2; i++){
        if(!v[i]) continue;
        cnt--;
        ans += v[i];
    }
    cout << ans << endl;
}