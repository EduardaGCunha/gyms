#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cout << "*";
    cout << endl;
    int amnt = (n&1) ? n/2 : n/2-1;
    int pos = 2;
    for(int i = 0; i < amnt; i++){
        //cout << pos << endl;
        cout << "*";
        for(int j = 2; j <= n-1; j++){
            if(j == pos || j == n-pos+1) cout << "*";
            else cout << " ";
        }
        pos++;
        cout <<"*";
        cout << endl;
    }

    amnt = (n&1) ? n/2-1: n/2-1;
    if(!(n&1)) pos--; 
    for(int i = 0; i < amnt; i++){
        //cout << pos << endl;
        cout << "*";
        for(int j = 2; j <= n-1; j++){
            if(j == pos || j == n-pos+1) cout << "*";
            else cout << " ";
        }
        pos--;
        cout <<"*";
        cout << endl;
    }

    for(int i = 0; i < n; i++) cout << "*";
    cout << endl;
}   
