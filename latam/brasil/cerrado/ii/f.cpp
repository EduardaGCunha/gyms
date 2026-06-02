#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 998244353;

//Matrix Exponentiation
struct matrix : vector<vector<int>> {
    int n, m;

    matrix(int n_, int m_, bool ident = false) : vector<vector<int>>(n_, vector<int>(m_, 0)), n(n_), m(m_) {
        if (ident) {
            assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}

    matrix(const vector<vector<int>>& c) : vector<vector<int>>(c),
    n(c.size()), m(c[0].size()) {}

    matrix operator*(const matrix &a) const {
        assert(m == a.n);
        matrix res(n, a.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < a.m; j++){
                for (int k = 0; k < m; k++){
                    res[i][j] = (res[i][j] + ((*this)[i][k] * a[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    matrix operator^(int e) const {
        matrix res(n,n,true);
        matrix base = *this;
        while (e) {
            if (e&1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
};

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}


int mod(int x) {
    return (x % MOD + MOD) % MOD;
}

void solve(){
    int a, b, n, m, fn, fm; cin >> a >> b >> n >> m >> fn >> fm;
    vector<vector<int>> bas = {{a, b}, {1, 0}};
    matrix base(bas);
    matrix mt = base ^ n;

    int c = mt[1][0];
    int d = mt[1][1];

    mt = base^(m);

    int e = mt[1][0];
    int f = mt[1][1];

    int det = mod((c*f)%MOD - (d*e)%MOD);
    int detx = mod((fn*f)%MOD - (fm*d)%MOD);
    int dety = mod((fm*c)%MOD - (fn*e)%MOD);



    int f0 = mod(detx*fastexpo(det, MOD-2));
    int f1 = mod(dety*fastexpo(det, MOD-2));
    cout << f1 << " " << f0 << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
