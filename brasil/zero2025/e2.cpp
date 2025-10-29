#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

vector<int> factorize(int x){
    vector<int> div; 
    for(int i = 2; i*i <= x; i++){
        while(!(x%i)) {
            //aq sempre vai pegar os gcd 
            div.push_back(i);
            x /= i;
        }
    }
    if(x > 1) div.push_back(x);
    return div;
}

//tamanho do pulo
signed main(){
    int y, k; cin >> y >> k;
    vector<int> div = factorize(y);
    int ans = 1, m = 1;
    
    for(auto u : div){
        //cout << u << " " << endl;
        int tam = min(k, u-1);
        ans += m*tam;
        m *= u;
        k -= tam;
    }
    
    cout << ans + m*k << endl;
    
}