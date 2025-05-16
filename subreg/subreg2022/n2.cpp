#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)


const int MAXN = 1e5+7;
int arr[MAXN], brr[MAXN], pfx[MAXN], sfx[MAXN];
multiset<int> lmaiores, restantes;
int k, l, soma = 0;


//adicionar um cara
void add(int x){
    if(lmaiores.size() < l){
        lmaiores.insert(x);
        soma += x;
    }else{
        //quero remover dos maiores e adicionar nos restantes
        if(!lmaiores.empty() && x > *lmaiores.begin()){
            int y = *lmaiores.begin();
            lmaiores.erase(lmaiores.begin());
            soma -= y;
            soma += x;
            lmaiores.insert(x);
            restantes.insert(y);
        }else{
            restantes.insert(x);
        }
    }
}

void balance(){
    while((int)lmaiores.size() > l){
        int y = *lmaiores.begin();
        soma -= y;
        lmaiores.erase(lmaiores.begin());
        restantes.insert(y);
    }

    while(lmaiores.size() < l && !restantes.empty()){
        auto it = prev(restantes.end());
        int y = *it;
        soma += y;
        lmaiores.insert(y);
        restantes.erase(it);
    }
}

void remove(int x){
    auto it = lmaiores.find(x);
    if(it != lmaiores.end()){
        soma -= x;
        lmaiores.erase(it);
    }else{
        it = restantes.find(x);
        restantes.erase(it);
    }
    balance();
}


signed main(){
    fastio;
    int n; cin >> n;
    //ja calculei os prefixo
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];
    cin >> k >> l;
    for(int i = 1; i <= n; i++){
        pfx[i] = arr[i-1] + pfx[i-1];
    }
    for(int i = n-1; i>= 0; i--){
        sfx[i] = sfx[i+1] + arr[i];
    }
    // for(int i = 0; i <= n; i++){
    //     cout << pfx[i] << " ";
    // }
    // cout << endl;

    // for(int i = 0; i <= n; i++){
    //     cout << sfx[i] << " ";
    // }
    // cout << endl;

    int maxsum = 0;

    for(int i = n-k; i < n; i++){
        add(brr[i]);
    }
    maxsum = max(maxsum, pfx[0] + sfx[n-k] + soma);

    for(int i = 1; i <= k; i++){
        remove(brr[n-k + i - 1]);
        add(brr[i - 1]);
        maxsum = max(maxsum, pfx[i] + sfx[n-k + i] + soma);
    }

    cout << maxsum << endl;
}