#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;
int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

void solve(){
    int n, x; cin >> n >> x;
    if(n-x > 365){
        cout << 0 << endl;
        return;
    }
    int p = 1;
    //calculo do 364*363*362...
    int cur = 364;
    for(int i = 0; i < n-x; i++){
        p = (p*cur)%MOD;
        cur--;
    }

    //calculando na mao n*(n-1)*(n-2)*...*(n-x+1)
    int num = 1;
    for(int i = n; i > x; i--){
        int k = i%MOD;
        num = (num*k)%MOD;
    }

    //365^(n-1)
    int den1 = fastexpo(365, n-1);
    int den= 1;
    //calculando na mao (n-x)!
    for(int i = 1; i <= (n-x); i++){
        den = (den*i)%MOD;
    }

    //multiplica os numeradores
    num = (num*p)%MOD;

    //cout << num << " " << den1 <<" " << den << endl;
    //invertendo
    den1 = fastexpo(den1, MOD-2);
    den = fastexpo(den, MOD-2);


    //multiplica os denominadores
    den = (den*den1)%MOD;
    int ans = (num*den)%MOD;

    cout << ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    //cout << fastexpo(365, MOD-2) << endl;
    while(t--){
        solve();
    }
}
