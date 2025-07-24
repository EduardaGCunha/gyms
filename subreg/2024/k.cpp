#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 102;
const int MAXS = 1e4+7;

int dp[MAXN][MAXS];

signed main() {
    fastio;
    int n, soma = 0; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        soma += arr[i];
    }

    if(soma&1){
        cout << -1 << endl;
        return 0;
    }
    //caso base onde nn tem nenhum conjunto, entao conseguimos fazer a soma 0
    dp[0][0] = 1;
    soma/=2;

    //p cada um dos valores q eu to adicionando no conjunto
    for(int i = 1; i <= n; i++){ 
        //consigo formar essa soma se adicionar ou nao esse valor?
        for(int j = 0; j <= soma; j++){
            //consigo formar essa soma se nao adicionar?
            dp[i][j] |= dp[i-1][j];
            //e se eu adicionar?
            if(arr[i] <= j) dp[i][j] |= dp[i-1][j-arr[i]];
        }
    }

    if(!dp[n][soma]){
        cout << -1 << endl;
        return 0;
    }   

    vector<int> a, b;
    int s = soma;
    for(int i = n; i > 0; i--){
        if(s >= arr[i] && dp[i-1][s-arr[i]]){
            a.push_back(arr[i]);
            s -= arr[i];
        }else{
            b.push_back(arr[i]);
        }
    }

    vector<int> ans;
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        if(s1 <= s2){
            s1 += a.back();
            ans.push_back(a.back());
            a.pop_back();
        }else{
            s2 += b.back();
            ans.push_back(b.back());
            b.pop_back();
        }
    }

    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}