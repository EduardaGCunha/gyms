#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    int n, marcel, machado; cin >> n >> machado >> marcel;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0) arr[i] += arr[i-1];
    }

    int pos; cin >> pos; 
    pos--;
    for(int i = 0; i < n; i++){
        //cout << arr[i] << " ";
        if(i == pos) continue;
        if(arr[i] + machado >= arr[pos] + marcel){
            cout << "SIM\n" << i+1 << endl;
            return 0;
        }
    }
    cout << "NAO\n";
}