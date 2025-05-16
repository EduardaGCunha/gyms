#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MAXN = 1e4+7;

/*
eu monto todas as bitmasks 
e checo oq acontece se eu setar o bit na jesima posicao
*/


signed main(){
    fastio;
    int n = 10;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    map<int, vector<int>> mp;
    mp[1] = {2, 5};
    mp[2] = {1, 3, 5, 6};
    mp[3] = {2, 4, 6, 7};
    mp[4] = {3, 7};
    mp[5] = {1, 2, 6, 8};
    mp[6] = {2, 3, 5, 7, 8, 9};
    mp[7] = {3, 4, 6, 9};
    mp[8] = {5, 6, 9, 10};
    mp[9] = {6, 7, 8, 10};
    mp[10] = {8, 9};
    
    int ans = 11;
    vector<int> best_seq;
    //montando todas as possíveis configurações
    for(int i = 0; i < (1<<n); i++){
        //função que conta quantos bits ligados têm
        int cnt = __builtin_popcount(i);
        
        //se tiver uma resposta menor do que essa, skipar
        if(cnt > ans) continue;

        //crio um novo array p/ nn alterar o original
        vector<int> brr(n+1);
        vector<int> seq;
        brr = arr;
        for(int j = 0; j < n; j++){
            //se o bit na posicao j estiver setado
            //quem eh o bit q esta setado?
            if(i&(1<<j)){
                seq.push_back(j+1);
                /*
                map q contém os botões que irei negar se o bit j estiver ligado
                */
                for(auto u : mp[j+1]){
                    brr[u] = !brr[u];
                }
            }
        }

        int pos = 1;
        //testando se todos os bits sao ligados essa configuracao
        for(int j = 1; j <= 10; j++){
            if(!brr[j]) pos = 0;
        }
        
        //se nao for, apenas continue 
        if(!pos) continue; 

        //essa eh uma resposta melhor do que a anterior?
        if(ans > cnt || (cnt == ans && seq < best_seq)){
            best_seq = seq;
            ans = cnt;
        }

    }

    if(ans > 10){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
        for(int i = 0; i < best_seq.size(); i++){
            if(i == best_seq.size()-1) cout << best_seq[i] << endl;
            else cout << best_seq[i] << " ";
        }
    }
}