#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 1e6+7;
int cnt[MAXN], spf[MAXN];

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /=2;
    }
    return res;
}

void mfp(){
    iota(spf, spf + MAXN, 0);
    for(int i = 2; i*i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i*i; j < MAXN; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> factor(int x){
    set<int> ans;
    //cout << "divisores primos do " << x << endl;
    while(x > 1){
        int p = spf[x];
        ans.insert(p);
        x /= p;
    }
    vector<int> res;
    for(auto u : ans){
        //cout << u << " ";
        res.push_back(u);
    }
    //cout << endl;
    return res;
}


signed main() {
    fastio;
    mfp();
    int n; cin >> n;
    for(int p = 0; p < n; p++){
        int x; cin >> x;
        vector<int> ret = factor(x);
        int k = ret.size();
        //cout << "multiplos de todos os primos q dividem " << x << endl;
        for(int i = 1; i < (1 << k); i++){
            int prod = 1;
            for(int j = 0; j < k; j++){
                if(i & (1 << j)) prod *= (ret[j]);
            }
            if(prod > 0) //cout << prod << " ";
            cnt[prod]++;
        }
        //cout << endl;
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        vector<int> p = factor(x);
        int k = p.size();
        int ans = n;
        for(int i = 1; i < (1 << k); i++){
            int prod = 1;
            for(int j = 0; j < k; j++){
                if(i & (1 << j)) prod *= (p[j]);
            }
            int tot = __builtin_popcount(i);
            if(tot&1) ans -= cnt[prod];
            else ans += cnt[prod];
        }
        //cout << ans << endl;
        cout << fastexpo(2, ans) << endl;
    }
}