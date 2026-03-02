#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

/*
leio o input de como elas estao originalmente
tudo oq eu preciso fazer eh criar todas as bitmasks e checar se ele esta conectado
*/

signed main(){
    fastio;
    int n; cin >> n;
    while(n >= 10){
        cout << n << endl;
        n = (n/10)*3 + n%10;
    }
    cout << n << endl;
}
