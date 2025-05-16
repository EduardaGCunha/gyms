#include <bits/stdc++.h>
using namespace std;

map<int, set<char>> mp;

void solve(){
    char a = 'a';
    for(int i = 2; i < 7; i++){
        for(int j = 0; j < 3; j++){
            mp[i].insert(a);
            a++;
        }
    }

    for(int i = 0; i < 4; i++){
        //cout << a << " ";
        mp[7].insert(a);
        a++;
    }
    //cout << endl;

    for(int i = 0; i < 3; i++){
        //cout << a << " ";
        mp[8].insert(a);
        a++;
    }
    //cout << endl;

    for(int i = 0; i < 4; i++){
        //cout << a << " ";
        mp[9].insert(a);
        a++;
    }

    //cout << endl;

}

int main(){
    solve();
    string s; cin >> s;
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        if(t.size() != s.size()) continue;
        int pos = 1;
        int j = 0;
        for(int j = 0; j < s.size(); j++){
            if(mp[s[j]-'0'].find(t[j]) == mp[s[j]-'0'].end()){
                //cout << s[j] << " " << t[j] << endl;
                pos = 0;
                break;
            }
        }
        if(pos) ans++;
    }
    cout << ans << endl;
}