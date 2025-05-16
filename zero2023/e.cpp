#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e4+7;

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> num;
    set<int> respostas;
    map<int, int> erro, novo_erro;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        num.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(erro.find(x) != erro.end())
            erro[x]++;
        else erro[x] = 1;
    }

    unordered_map<int, int> mp;
    for(auto e : erro){ // erros
        bool ok = true;
        int alvo = num[0] + e.first;
        novo_erro = erro;
        novo_erro[e.first]--;
        //cout << "alvo:" << alvo << endl;
        for(int i=1 ; i<n ; i++){
            auto val = novo_erro.find(abs(num[i] - alvo));
            //cout << "i:" << num[i] << " p:" << abs(num[i] - alvo);
            if(val != novo_erro.end() && (*val).second>0){
                (*val).second--;
                continue;
            }
            else {
                ok = false;
                //cout << " N TEM" << endl;
                break;
            }
        }
        if(ok){
            respostas.insert(alvo);
        }
    }
    for(auto e : erro){ // erros
        bool ok = true;
        int alvo = num[0] - e.first;
        novo_erro = erro;
        novo_erro[e.first]--;
        //cout << "alvo:" << alvo << endl;
        for(int i=1 ; i<n ; i++){
            auto val = novo_erro.find(abs(num[i] - alvo));
            //cout << "i:" << num[i] << " p:" << abs(num[i] - alvo);
            if(val != novo_erro.end() && (*val).second>0){
                (*val).second--;
                continue;
            }
            else {
                ok = false;
                //cout << " N TEM" << endl;
                break;
            }
        }
        if(ok){
            respostas.insert(alvo);
        }
    }

    for(auto resp: respostas){
        cout << resp << endl;
    }
}