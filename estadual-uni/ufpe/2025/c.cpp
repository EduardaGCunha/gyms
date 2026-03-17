#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MOD = 1e9 + 7;

int fastexpo(int a, int b){
    int res = 1;
    a %= MOD;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int cnt = 0, sum = 0, ans = 0, f = -1, lst = -1;
    for(int i = 0; i <=n; i++){
        int x;
        if(i == n) x = 0;
        else cin >> x;
        if(x == 0){
            if(cnt&1){
                ans = max({ans, sum - f, lst});
            }else ans = max(ans, sum);
            cnt = 0, sum = 0, f = -1, lst = -1;
        }else{
            int k = (x == 1 || x == -1) ? 0 : (int)log2(abs(x));
            sum += k;
            if(x < 0){
                cnt++;
                if(f == -1) f = sum;
                else lst = sum - k;
            }    
        }
    }
    cout << fastexpo(2, ans) << endl;
}

signed main() {
    fastio;
    solve();
    return 0;
}