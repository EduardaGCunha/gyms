#include <bits/stdc++.h>
using namespace std;
 
#define int long long

int despojado(int x){
    if(x == 1) return 0;

    int p = 1;
    for(int i = 2; i <= sqrt(x); i++){
        if((x % (i*i)) == 0){
            return 0;
        }else if(x % i == 0){
            p = 0;
        }
    }

    return !p;
}

signed main(){
    int n; cin >> n;

    int ans = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            ans += despojado(i);
            if(i != n/i) ans += despojado(n/i);
        }
    }

    cout << ans << endl;
}
 
