#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int qtd = n-i;
        for(int j = 0; j < qtd; j++) cout << " ";
        for(int j = 0; j < i; j++){
            if(j == i-1) cout << "*";
            else cout << "* ";
        }
        for(int j = 0; j < qtd; j++) cout << " ";
        cout << endl;
    }
}   
