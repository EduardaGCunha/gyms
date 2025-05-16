#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main(){
    fastio;
    string s; cin >> s;
    int n = s.size();
    string a = "", b = "";
    for(int i = 0; i < n; i++){
        if(i&1) a+= s[i];
        else b += s[i];
    }
    cout << b << endl << a << endl;
}
