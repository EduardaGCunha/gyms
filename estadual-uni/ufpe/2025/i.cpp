#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int>> v;
    Matrix(int n) {
        v.assign(n, vector<int>(n, 0));
    }
    Matrix(vector<vector<int>> vec) : v(vec) {}

    static Matrix identity(int n) {
        Matrix res(n);
        for (int i = 0; i < n; i++) res.v[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        int n = v.size();
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (v[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    res.v[i][j] = (res.v[i][j] + v[i][k] * other.v[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix operator^(int p) const {
        Matrix res = identity(v.size());
        Matrix base = *this;
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};

void solve() {
    int n, x, y; cin >> n >> x >> y;

    if (n&1) cout << "Samuell" << endl;
    else cout << "Lleumas" << endl;

    if (n == 1) {
        cout << x % MOD << endl;
        return;
    }
    if (n == 2) {
        cout << y % MOD << endl;
        return;
    }

    Matrix T({{1, 1}, {1, 0}});
    T = T ^ (n - 2);

    int ans = (T.v[0][0] * (y % MOD) + T.v[0][1] * (x % MOD)) % MOD;
    cout << ans << endl;
}

signed main() {
    fastio;
    solve();
    return 0;
}