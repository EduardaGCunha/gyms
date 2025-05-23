#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

int grid[21][21];

int main(){
    fastio;
    int n, m, p, s; cin >> n >> m >> p >> s;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        grid[a][b] = 1;
        grid[b][a] = 1;
    }

    int ans = 0;
    //formo todas as bitmasks
    for(int i = 0; i < (1 << n); i++){
        int pcnt = 0, P = 0;
        //aq eu quero pegar quantos paes tem
        //se tiver mais q 1, ent eh invalido, do contrario, eu quero pegar esse pao
        for(int j = 0; j < p; j++){
            if(i&(1<<j)){
                pcnt++;
                P = j;
            }
        }
        //se tiver mais q um pao, ent eh invalido
        if(pcnt != 1) continue;

        //a msm logica do pao se aplica aq pra salsicha
        int scnt = 0, S = 0;
        for(int j = p; j < p + s; j++){
            if(i&(1<<j)){
                scnt++;
                S = j;
            }
        }
        if(scnt != 1) continue;

        //se essa combinacao de pao e salsicha for invalida, tbm dou um continue
        if(grid[P][S]) continue;

        /*
        essa parte aq eh pra saber quais ingredientes eu to escolhendo
        */
        vector<int> pos; 
        int ehpos = 1;
        for(int j = p+s; j < n; j++){
            if(i&(1<<j)){
                //se essa combinacao de pao + ingrediente ou pao + salsicha for invalida, ai eu tbm paro de contar
                if(grid[P][j] || grid[j][S]){
                    ehpos=0;
                    break;
                }
                //do contrario vo adicionar ele no loop
                pos.push_back(j);
            }
        }

        /*
        pra cada par de ingrediente, vou checar se eles sao pares validos 
        no pior dos casos, se tivermos somente 1 pao e 1 salsicha e 18 ingredientes, essa checagem
        dos pares levaria 18*18 operacoes = 324. Isso eh rapidinho e eh super tranquilo!
        tbm nesse pior dos casos, teriamos um total de 2^(18) combinacoes de ingredientes, o que eh
        262144, mais ou menos 2*(10^5) 
        teriamos entao 3*(10^2)*2*(10^5), o que é mais ou menos 6*(10^7), o que passa em 0.5 segundos
        */
        for(int j = 0; j < (int) pos.size(); j++){
            for(int k = j+1; k < (int) pos.size(); k++){
                if(grid[pos[j]][pos[k]]){
                    ehpos = 0;
                    break;
                }
            }
        }
        if(ehpos) ans++;
    }

    cout << ans << endl;
}