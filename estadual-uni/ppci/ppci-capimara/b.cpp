#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    int tot = n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 20) tot -=2;
        if(x >= 15 && x <= 19) tot -=1;
    }

    if(tot <= 0) cout << "O BRUTO FOI DERROTADO\n";
    else cout << "O BRUTO ESTA VIVO TPK PARA O GRUPO\n";
}

signed main(){
	fastio;
    int t;
    t = 1;
	while(t--){
		solve();
	}
}