#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.size();
    string t ="";
    for(int i = 0; i < n; i++) t += "_";

    char a;
    while(cin >> a && a != '*'){
        for(int i = 0; i < n; i++){
            if(s[i] == a) t[i] = a;
        }
        cout << t << endl;
    }
} 