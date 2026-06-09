#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int fastexpo(int a, int b, int m){
    int res = 1LL;
    while(b > 0){
        if(b&1) res = (a*res)%m;
        a = (a*a)%m;
        b >>=1;
    }
    return res;
}

signed main(){
    fastio;
    int b, e, m; cin >> b >> e >> m;
    cout << fastexpo(b, e, m) << endl;
}   
