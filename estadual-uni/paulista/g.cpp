#include <bits/stdc++.h>
using namespace std;

int main(){
    int pos = 0;
    string s; cin >> s;
    string t = s;
    if(s[0] == '?'){
        t[0] = 'B';
        if(t == "BR-SP") pos = 1;
    }else if(s[2] == '?'){
        t[2] = '-';
        if(t == "BR-SP") pos = 1;
    }else if(s[1] == '?'){
        t[1] = 'R';
        if(t == "BR-SP") pos = 1;
    }else if(s[3] == '?' && s[4] == 'P'){
        pos =  2;
    }else if(s[4] == '?' && s[3] == 'S') pos = 2;
    if(pos == 1) cout << 'S' << endl;
    else if(pos==2) cout << 'T' << endl;
    else cout << 'N' << endl;
} 