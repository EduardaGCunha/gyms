#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    long double n,cnt=0; cin >> n;
    while(n>1){
        n=n/2;

        cnt++;
    }
    cout<<cnt+1<<endl;
    

return 0;
}