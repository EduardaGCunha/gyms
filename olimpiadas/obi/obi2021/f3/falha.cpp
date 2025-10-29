#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    int n; cin >> n;
    map<string, int> mp;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s]++;
        v.push_back(s);
    }

    //the amount will be how many combinations i can form with the number at mp - n*(n-1)/2

    int ans = 0;
    vector<string> fim;
    for(auto u : v){
        set<string> st;
        fim.push_back(u);
        st.insert(u);
        for(int i = 0; i <= (int) u.size(); i++){
            for(int j = i; j <= (int) u.size(); j++){
                string t = u.substr(i, j-i);
                //cout << t << " ";
                if(st.find(t) != st.end()) continue;
                st.insert(t);
                fim.push_back(t);
            }
        }
        //cout << endl;
    }

    for(auto u : fim){
        //cout << u << " ";
        if(mp.find(u) != mp.end()) ans += mp[u];
    }
    //cout << endl;
    cout << ans - n << endl;


}