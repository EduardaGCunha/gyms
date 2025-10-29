#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, a, d; cin >> n >> a >> d;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(abs(x-a) <= d) cnt++;
    }
    cout << cnt << endl;
}