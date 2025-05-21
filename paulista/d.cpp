#include <bits/stdc++.h>
using namespace std;

int n, m, p, s, total, aux, qtd_ingr;

bool eh_pao(int x){
    return (x >= 1) && (x<=p);
}

bool eh_sals(int x){
    return (x > p) && (x<=p+s);
}

bool eh_ingr(int x){
    return x>(p+s);
}

int main(){
    cin >> n >> m >> p >> s;
    qtd_ingr = n-p-s;
    total = p*s*((1<<qtd_ingr));
    cout << "total:" << total << " qtd_i:" << qtd_ingr << endl;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a, b);
        if(eh_pao(a) && eh_sals(b)){
            cout << "ps:" << (1<<qtd_ingr)-1 << endl;
            total -= (1<<qtd_ingr)-1;
        }
        else if(eh_pao(a) && eh_ingr(b)){
            cout << "pi:" << s*(1<<(qtd_ingr-1)) << endl;
            total-= s*(1<<(qtd_ingr-1));
        }
        else if(eh_sals(a) && eh_ingr(b)){
            cout << "si:" << p*(1<<(qtd_ingr-1)) << endl;
            total-= p*(1<<(qtd_ingr-1));
        }
        else if(eh_ingr(a) && eh_ingr(b)){
            aux = (1<<(qtd_ingr-2));
            cout << "ii:" << aux << endl;
            total-= aux;
        }

    }
    cout << total << endl;
    
} 

/*
vector<int> comb;
    for(int i=0 ; i<(1<<20); i++){
        comb.push_back(i);
    }

    //cout << comb.size() << endl;
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        int ab = 0, bb = 0;
        for(auto u : comb){
            for(int j = 0; j < 20; j++){
                if(u&(1<<j)){
                    if(j == a-1) ab=1;
                    if(j == b-1) bb=1;
                }
            }
            if(ab == 1 && bb == 1) continue;
            else ans++;
        }
    }
    cout << ans << endl;
*/