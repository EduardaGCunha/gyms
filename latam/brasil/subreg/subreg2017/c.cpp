#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int lcm(int a, int b){
    return a*b/(__gcd(a, b));
}
signed main(){
    fastio;
    int n, l; cin >> n >> l;
    int x = 1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        x = lcm(a, x);
    }

    int cur = x, ans = 1;
    for(int i = 2; i < 1e6; i++){
        int a = lcm(x, i);
        if(a <= l && a > cur){
            cur = a;
            ans = i;
        }
    }

    cout << ans << endl;
}