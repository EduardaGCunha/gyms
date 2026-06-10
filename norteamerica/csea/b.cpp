#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        vector<string> v(31, "");
        string s; cin >> s;
        int pot = 1, idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(i + 1 == pot*2){
                pot *= 2;
                idx++;
            }
            v[idx] += s[i];
        }
        for(int i = 0; i < 31; i++){ 
            sort(v[i].begin(), v[i].end());
            cout << v[i];
        }
        cout << endl;
    }
}   
