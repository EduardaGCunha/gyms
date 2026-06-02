#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int n, p; cin >> n >> p;
    int vic = 3, cnt = 0;
    while(p > 0){
        p -= vic;
        cnt++;
    }
    if(cnt <= n) cout << "Sim\n";
    else cout << "Nao\n";
}