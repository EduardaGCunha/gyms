#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    int a, b; cin >> a >> b;
    for(int i = 1; i <= a; i++){
        if(!(a%i) && b >= (a - i)){
            cout << i << endl;
            return 0;
        }
    }
}