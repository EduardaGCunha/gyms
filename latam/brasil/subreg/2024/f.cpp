#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 41;
int fib[MAXN];

signed main() {
    fastio;
    int n; cin >> n;

    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 41; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    cout << fib[n] << endl;
}