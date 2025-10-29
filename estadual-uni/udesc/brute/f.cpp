#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

bool quadrado(int a, int b, int c, int d){
    if(b == d && a + c == d) return true;
    if(a == c && b + d == a) return true;
    return false;
}

signed main(){
    fastio;
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    int pos = 0;
    if(quadrado(a, b, c, d)) pos = 1;
    if(quadrado(a, b, d, c)) pos = 1;
    if(quadrado(b, a, c, d)) pos = 1;
    if(quadrado(b, a, d, c)) pos = 1;
    cout << (pos ? "SIM\n" : "NAO\n");
}