#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t, u = ""; cin >> s;

    for(auto c : s){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            t+= c;
        }
    }

    u = t;
    reverse(t.begin(), t.end());
    if(u == t) cout << 'S' << endl;
    else cout << 'N' << endl;
}