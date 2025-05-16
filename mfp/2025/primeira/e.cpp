#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

/*
eh garantido q sempre havera uma resposta
tenho q achar todas as posicoes tal q uma posicao adjacente tenha o msm numero
ent posso aumentar em 1 o valor 
o problema eh, se eu aumentar em 1 e de alguma forma eu acabar criando uma nova
subarvore q tem valores iguais?
eh garantido q ha resposta, mas eu devo achar uma resposta otima 
parece dp ou algo com grafo
nn sei como modelar nada parecido com dp
se eu fizer lago greedy tipo somar 1 e checar se vai ficar igual a qualquer parede talvez funcione
ai eu olharia so pra cima e pra esquerda
*/

const int MAXN = 101;
int grid[MAXN][MAXN];
int n, m;

signed main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int pos = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int change = 0;
            if(i > 0){
                if(grid[i][j] == grid[i-1][j]) change = 1;
            }
            if(j > 0){
                if(grid[i][j] == grid[i][j-1]) change = 1;
            }
            if(change){
                grid[i][j]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
}
