#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int n; cin >> n;
    cin.ignore(); 
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int gt = 1;
        for(int j = 0; j < s.size(); j++){
            if(gt){
                char c = toupper(s[j]);
                cout << c;
                gt = 0;
            }
            if(s[j] == ' ') gt = 1;
        }
        cout << endl;
    }
}   
