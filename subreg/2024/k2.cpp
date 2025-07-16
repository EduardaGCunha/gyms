#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int s = 0;  
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        s += v[i];
    }
    vector<bitset<10007>> dp(n + 1);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        dp[i] |= (dp[i - 1] << v[i]);
    }
    if(s % 2 == 1 or !dp[n][s / 2]) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> l, r;
    s /= 2;
    for(int i = n; i; i--) {
        if(dp[i - 1][s]) l.push_back(v[i]);
        else r.push_back(v[i]), s -= v[i];
    }
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(a <= b) {
            cout << l.back() << " \n"[i == n - 1];
            a += l.back();
            l.pop_back();
        } else {
            cout << r.back() << " \n"[i == n - 1];
            b += r.back();
            r.pop_back();
        }
    }
    return 0;
}