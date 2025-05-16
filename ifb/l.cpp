#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAXN = 1e6+7;
int arr[MAXN], brr[MAXN], ans[MAXN];

signed main(){
    winton;
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i] >> brr[i];
    }

    int bestA = 0, bestX = 0;
    for(int i = 0; i < (1<<n); i++){
        int a = 0, q = 0, idx = 0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                a += arr[j];
                q += brr[j];
                idx++;
            }
        }
        if(a <= x){
            ans[idx] = max(ans[idx], q);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}