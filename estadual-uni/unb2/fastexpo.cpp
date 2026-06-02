#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

//a = 3, b = 11
//res *= 3
//a = 3*3 => 9
// a= 81 
//res *= 9 
//


int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b%2 == 1) res = (res*a);
        a = (a*a);
        b /=2; 
    }
    return res;
}

signed main() {
    int a, b;
    cin >> a >> b;
    cout << fastexpo(a, b) << endl;
}