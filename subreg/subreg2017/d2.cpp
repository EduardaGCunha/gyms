#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res *= a;
        a*=a;
        b/=2;
    }
    return res;
}

signed main(){
    int n; cin >> n;
    int cnt = 0;
    for(int i = 2; i*i <= n; i++){
        if(!(n%i)){
            cnt++;
            while(!(n%i)){
                n/=i;
            }
        }
    }
    if(n>1) cnt++;
    int ans = fastexpo(2, cnt)- cnt - 1;
    cout << ans << endl;

}