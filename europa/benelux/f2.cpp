#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, cap, idx=0;
    cin >> n >> cap;
    vector<int> pessoa(n), min_sai(n, -1);
    for(int i=0 ; i<n ; i++){
        cin >> pessoa[i];
    }

    for(int i=0 ; i<n ; i++){
        int k=cap;
        while(k>0 && idx<=i){
            if(pessoa[idx]<k){
                k-=pessoa[idx];
                min_sai[idx++] = i;
            }
            else{
                pessoa[idx] -=k;
                k=0;
            }
        }
    }

    int menor_idx=0;
    for(int i=1 ; i<n ; i++){
        if(min_sai[i]<0) continue;
        int aux = min_sai[menor_idx] - menor_idx;
        int demora = min_sai[i] - i ;
        if(min_sai[menor_idx] == -1) menor_idx = i;
        else if(aux>demora){
            menor_idx = i;
        }
    }
    if(min_sai[menor_idx] < 0){
        cout << "impossible" << endl;
    }
    else cout << menor_idx << endl;
}