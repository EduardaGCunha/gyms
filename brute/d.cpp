#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    fastio;
    int n; cin >> n;
    int par1 = 0, impar1 = 0, par2 = 0, impar2 = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x&1) impar1++;
        else par1++;
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x&1) impar2++;
        else par2++;
    }

    if(impar1 > par2 || par1 > impar2) cout << "NAO\n";
    else cout << "SIM\n";
}