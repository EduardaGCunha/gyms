#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 107;
int fat[MAXN];

signed main() {
    fastio;
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fat[i] = i*fat[i-1];
    }

    int t; cin >> t;
    int amnt = 0;
    while(t--){
        int g, c; cin >> g >> c;
        amnt += (g - c);
        if(amnt > 12){
            cout << -1 << endl;
            continue;
        }

        if(amnt == 0){
            cout << 1 << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0; i <= min(4LL, amnt); i++){
            int v1 = fat[amnt]/(fat[i]*fat[amnt-i]);
            for(int j = 0; j <= min(4LL, amnt-i); j++){
                int x = amnt - i - j;
                if(x >= 0 && x <= 4){
                    int v2 = fat[amnt-i]/(fat[j]*fat[amnt-i-j]);
                    ans += (v1*v2); 
                }
            }
        }
        cout << ans << endl;
    }
}