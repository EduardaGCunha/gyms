#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    string s; cin >> s;
    int n; cin >> n;
    map<pair<char, char>, int> mp;
    for(int i = 0; i < n; i++){
        char a, b; cin >> a >> b;
        mp[{a, b}]++;
    }

    for(int i = 0; i < s.size()-1; i++){
        if(mp[{s[i], s[i+1]}] > 0){
            continue;
        }else{
            cout << "NAO\n";
            return 0;
        }
    }
    cout << "SIM\n";
}
