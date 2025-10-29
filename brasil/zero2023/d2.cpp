#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e4+7;
int arr[MAXN];

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> brr(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> brr[i];
        mp[brr[i]]++;
    }

    sort(brr.begin(), brr.end());
    //p cada erro, quais sao as solucoes?
    set<int> solucoes;
    for(int i  = 0; i < n; i++){
        if (arr[0] + brr[i] > 0) solucoes.insert(arr[0] + brr[i]);
        if (arr[0] - brr[i] > 0) solucoes.insert(arr[0] - brr[i]);
    }
    //aq sao formadas 1e4 solucoes

    //p cada chute, eu consigo encontrar um erro tal que essa solucao exista?
    for(int i = 1; i < n; i++){
        //se sim, eu crio um novo set contendo somente essas solucoes possiveis
        set<int> novo;
        for(auto u : solucoes){
            int diff = llabs(u - arr[i]);
            if (mp.count(diff) > 0) novo.insert(u);
        }
        solucoes.swap(novo);
    }

    vector<int> ans;
    for(auto u : solucoes){
        vector<int> comp;
        for(int i = 0; i < n; i++){
            comp.push_back(abs(arr[i] - u));
        }
        sort(comp.begin(), comp.end());
        if(brr == comp) ans.push_back(u);
    }
    
    for(auto u : ans){
        if(u <= (int) 1e9) cout << u << endl;
    }

}