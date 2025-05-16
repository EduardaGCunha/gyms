#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long

signed main(){
    fastio;
    int a, p, v; cin >> a >> p >> v;

    //c vai ser pelo menos maior ou igual
    int d = v/2;
    int c = (p*v - a)/d;
    cout << c << endl;
    
}