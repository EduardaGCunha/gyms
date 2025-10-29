#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

/*
recebo o raio dos 3 circulos
vai estar dividido em N linhas
vai me perguntar, qual o caminho mais proximo? 
faz sentido q o caminho mais proximo seja pegar a diferenca entre a linha atual e a linha final 
indo pela direita ou pela esquerda? 
ent ai eu tenho q calcular a distancia entre essa linha e a outra a partir do raio
como sao so 3 raios, eu posso testar a melhor diferenca
ent acho q eu posso responder online talvez? 
e o arco eu pego a circunferencia do circulo de raio i
a fatia seria isso dividido por n pq dai daria tudo igual
*/

const double INF = 1e18;
double PI = 3.14159265359;
double r[3];
int n, q;

void solve(){
    int c1, l1, c2, l2; cin >> c1 >> l1 >> c2 >> l2;
    c1--, l1--, c2--, l2--;
    int distancia_angular = abs(l1 - l2);
    int d = min(distancia_angular, n-distancia_angular);
    //cout << distancia_angular << " " << d << endl;
    double ans = INF; 
    for(int i = 0; i < 3; i++){
        double arco = ((2*PI*r[i])/n)*d;
        //cout << 2*PI*r[i] << " " << 2*PI*r[i]/n << endl;
        double rad = abs(r[c1] - r[i]) + abs(r[c2] - r[i]);
        //cout << arco << " " << rad << " " << ans << endl;
        ans = min(ans, rad + arco);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}

signed main(){
    fastio;
    cin >> r[0] >> r[1] >> r[2];

    cin >> n >> q;

    while(q--){
        solve();
    }
}
