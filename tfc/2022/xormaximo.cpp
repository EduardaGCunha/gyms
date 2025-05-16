#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int dp[3010][(1<<15)];
int arr[3010];

int main(){
    fastio;
    int n; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1, arr+n+1);
    int ini = 0;
    while(n != 0 && arr[n] >= (1<<15)){
        ini ^= arr[n];
        n--;
    }

    //dp eh guardando todos os xors possiveis utilizando i elementos 
    dp[0][0] = 1;
    //index
    for(int i = 1; i <= n; i++){
        //p cada xor possivel de 0 ate 2^15
        for(int j = 0; j < (1<<15); j++){
            dp[i][j] = dp[i-1][j] | dp[i-1][j^(arr[i])];
        }
    }

    int ans = 0;
    for(int i = 0; i <(1<<15); i++){
        if(dp[n][i]) ans = max(ans, ini^i);
    }

    cout << ans << endl;

}