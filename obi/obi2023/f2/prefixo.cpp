#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    string s, t; cin >> n >> s >> m >> t;
    
    int i = 0, j = 0;
    int cnt = 0;
    while(i < n && j < m && s[i] == t[j]){
        i++, j++;
        cnt++;
    }



    cout << cnt << endl;
}