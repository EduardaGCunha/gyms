#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, soma = 0, meio = 0; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        soma += arr[i];
    }
    meio = soma/n;
    int atual = arr[0];
    int pos = 0;
    for(int i = 0; i < n; i++){
    if(arr[i]>atual && arr[i]<= meio){
        atual= arr[i];
        pos=i;
    }
    
    }
}