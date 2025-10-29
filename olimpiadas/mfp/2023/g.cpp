#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
satisfação de um convidado como o produto da quantidade de rositas
e de tulipas q ele visita
determinar que tipo de flor colocar em cada posicao da sequencia
p/ maximizar a soma da satisfação de todos os convidados
recebo l, r

   1 2 3 4 5
0  1 3 3 2 1 0 

maximizar a soma da satisfacao de todos os candidatos
a satisfacao de um candidato eh o produto 

*/

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
    }
    int tog = 0;
    for(int i = 0; i < n; i++){
        if(tog){
            cout << "1";
            tog = 0;
        }else{
            cout << "0";
            tog = 1;
        }
    }
    cout << endl;
}


signed main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}