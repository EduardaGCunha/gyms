#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    int pos = 1;
    for(int i = 0; i < 5; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 35;
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){}
        else pos = 0;
    }
    for(int i = 7; i <= 9; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 35;
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){}
        else pos = 0;
    }
    if(s == "daniel sad") return 1;
    else return 0;
    cout << s << endl;
}

int main(){
    string s;
    getline(cin, s);
    int i = 0, j = 10, n = s.size();
    while(j <= n){
        string t = s.substr(i, j);
        if(check(t)){
            
        }
        i++, j++;
        cout << t << endl;
    }
}