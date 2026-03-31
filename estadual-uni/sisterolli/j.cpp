#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long


/*
p todo multiplo de 2 incluindo 1
quantas maneiras eu consigo escolher multiplos de 4 maiores q esse multiplo de 2

*/

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum = (sum ^(k));
            }
            if(sum != 0) continue;
            cout << i << " " << j << " " << sum << endl;
        }
    }
    int ans = 0;
    int a = (n-3)/4 + 1 + 1;
    int b = (n-1)/4 + 1;
    if(n >= 1) ans += b*(b-1)/2;
    if(n >= 3) ans += a*(a-1)/2;
    cout << ans << endl;
}