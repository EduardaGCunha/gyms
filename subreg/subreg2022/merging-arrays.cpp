#include <bits/stdc++.h>
using namespace std;
/*
macro para substituir int por long long
isso é necessário pois os números podem ser 
até 1e9, e isso não cabe em um inteiro (1e8)
*/
#define int long long

//quando usando essa macro, a main precisa
//retornar signed
signed main(){
    int n, m; cin >> n >> m;
    int arr[n], arr2[m];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> arr2[i];

    int i = 0, j = 0;
    vector<int> res;
    while(i < n && j < m){
        if(arr[i] <= arr2[j]){
            res.push_back(arr[i]);
            i++;
        }else{
            res.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n){
        res.push_back(arr[i]);
        i++;
    }
    while(j < m){
        res.push_back(arr2[j]);
        j++;
    }
    for(auto u : res){
        cout << u << " ";
    }
    cout << endl;
}