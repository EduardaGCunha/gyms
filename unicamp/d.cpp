#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

string fun(string s){
    int pos = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'H'){
            pos = i;
            s[i] = 'T';
            break;
        }
    }

    for(int i = 0; i < pos; i++){
        s[i] = 'H';
    }
    return s;
}

signed main() {
    fastio;
    string s; cin >> s;
    vector<string> t; 
    string fim(s.size(), 'T');
    //cout << fim << endl;
    while(s != fim){
        t.push_back(s);
        //cout << s << endl;
        s = fun(s);
    }
    t.push_back(fim);
   // cout << fim << endl;
    cout << t.size() << endl;
    for(auto u : t) cout << u <<  endl;
}