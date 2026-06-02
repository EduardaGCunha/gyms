#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    int n, m; cin >> n >> m;
    int k = n+1LL;
    int amnt = __builtin_popcountll(k);
    if(amnt == m){
        cout << k << endl;
        return 0;
    }else if(amnt < m){
        for(int i = 0; i < 62; i++){
            if(!(k&(1LL<<i))){
                k |= (1LL<<i);
                amnt++;
            }
            if(amnt == m) break;
        }
        cout << k << endl;
    }else{
        while(amnt > m){
            int seq = 0;
            for(int i = 0; i < 62; i++){
                if(amnt <= m) break;
                if(k&(1LL<<i)){
                    seq++;
                    k ^= (1LL<<i);
                }else if(seq){
                    amnt -= seq-1;
                    k ^=(1LL<<i);
                    break;
                }
            }
        }
        if(amnt == m){
            cout << k << endl;
            return 0;
        }else if(amnt < m){
            for(int i = 0; i < 62; i++){
                if(!(k&(1LL<<i))){
                    k |= (1LL<<i);
                    amnt++;
                }
                if(amnt == m) break;
            }
            cout << k << endl;
        }

    }
}
