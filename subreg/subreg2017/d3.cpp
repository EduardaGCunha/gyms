#include <bits/stdc++.h>
using namespace std;
 
#define int long long

const int MAXN = 1e6+1;
int primo[MAXN];

void crivo(){
    for(int i = 2; i <= MAXN; i++){
        if(primo[i] == -1){
            primo[i] = 1; 
            for(int j = i+i; j <= MAXN; j += i){
                primo[j] = 0;
            }
        }
    }
}

signed main(){
    int n; cin >> n;

    int ans = 0;
    for(int i = 2; i <= MAXN; i++) primo[i] = -1;
    crivo();
    for(int i = 2; i <= sqrt(n); i++){
        if(primo[i] && !(n%i)){
            
            ans++;
        }
    }
    cout << (1<<ans) - ans - 1 << endl;

}