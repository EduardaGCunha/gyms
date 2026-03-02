#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4*1e3+1;

#define int long long
int arr[MAXN];
 int a, b, c, d;

// bool check(int i){
//     if(i%b && (c%i))
// }

signed main(){
    cin >> a >> b >> c >> d;

    for(int i = 1; i*i <= c; i+=a){
        if(c%i) continue;
        if(i%b == 0) continue;
        if((c%i) != 0) continue;
        if(d%i == 0) continue;
        break;
    }

    // cout << n << endl;

}