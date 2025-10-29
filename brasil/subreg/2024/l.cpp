#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 32;
int cnt[MAXN];
//acumula todos os 

signed main() {
    fastio;
    int n; cin >> n;
    int arr[n];
    int val = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        val |= arr[i];
        //acumulando todos os valores
        for(int j = 0; j < 31; j++){
            if(arr[i]&(1<<j)) cnt[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        cout << val << " ";
        for(int j = 0; j < 31; j++){
            if(cnt[j]){
                cnt[j]--;
                if(!cnt[j]) val ^=(1<<j);
            }
        }
    }
    cout << endl;

}