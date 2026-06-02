#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int n; cin >> n;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    arr[n] = arr[n-1];

    int qtd = 1, tot = 0, cursum = arr[0];
    for(int i = 1; i < n; i++){
        if((cursum&(arr[i])) != 0){
            qtd++;
            tot += cursum;
            cursum = arr[i];
        }else cursum += arr[i];
    }

    tot += cursum;

    cout << tot << " " << qtd << endl;
}
