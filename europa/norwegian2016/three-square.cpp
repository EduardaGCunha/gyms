#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

bool quadrado(int a, int b, int c, int d, int e, int f){
    if(a + c + e == d && d == f && d == b) return true;
    if(a + e == d + e && b + c == f) return true;
    return false;
}

int main(){
    fastio;
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    int pos = 0;
    //abcdef
    //abcdfe
    //abdcef
    //abdcfe
    //bacdef
    if(quadrado(a, b, c, d, e, f)) pos = 1;
    if(quadrado(a, b, c, d, f, e)) pos = 1;
    if(quadrado(a, b, d, c, e, f)) pos = 1;
    if(quadrado(a, b, d, c, f, e)) pos = 1;
    if(quadrado(b, a, c, d, e, f)) pos = 1;
    if(quadrado(b, a, d, c, e, f)) pos = 1;
    if(quadrado(b, a, d, c, f, e)) pos = 1;
    if(pos) cout << "YES\n";
    else cout << "NO\n";

}