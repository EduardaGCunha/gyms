#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main(){
    fastio;
    int n; cin >> n;
    while(n >= 10){
        cout << n << endl;
        n = (n/10)*3 + n%10;
    }
    cout << n << endl;
}
