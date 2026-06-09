#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int MAXN = 26;
int C[MAXN][MAXN];


signed main(){
    int n, p, k; cin >> n >> p >> k;
    for(int i = 0; i < MAXN; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    int mx = n, curp = p - 1;
    for(int i = 0; i < p; i++){
        for(int j = 1; j <= mx; j++){  
            if(j - 1 < curp) continue;
            int ways = C[j - 1][curp];
            if(k <= ways){
                cout << j << (i == p - 1 ? "" : " "); 
                mx = j - 1; 
                curp--;    
                break;
            }else k -= ways;
            
        }
    }
    cout << endl;
}