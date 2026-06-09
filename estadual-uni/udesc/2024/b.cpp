#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int n, x; cin >> n >> x;
    int sum = 0, pos = 0, cnt1 = 0, cnt2= 0;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        sum ^= (k%3);
        if(!(k%3)) pos = 1;
        else if((k%3) == 1) cnt1++;
        else cnt2++;
    }

    if(!sum){
        if(pos || !(x&1)) cout << "Giovana\n";
        else cout << "Julia\n";
    }else{
        if(x == 0) cout << "Julia\n";
        else if((cnt1+cnt2)&1 || (!(x&1) && !pos)) cout << "Julia\n";
        else cout << "Giovana\n";
    }
    
}   
