#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int INF = 1e12;
signed main(){
    fastio;
    int n, d; cin >> n >> d;
    pair<int, int> arr[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n);

    vector<int> pfx(n+1, 0), sfx(n+1, 0);
    pfx[0] = arr[0].second;
    int cur = pfx[0];
    for(int i = 1, j = 0; i < n; i++){
        cur += arr[i].second;
        while(arr[i].first - arr[j].first > d){
            cur -= arr[j].second;
            j++;
        }
        pfx[i] = max(cur, pfx[i-1]);
    }

    sfx[n-1] = arr[n-1].second;
    cur = sfx[n-1];
    for(int i = n-2, j = n-1; i >= 0; i--){
        cur += arr[i].second;
        while(arr[j].first - arr[i].first > d){
            cur -= arr[j].second;
            j--;
        }
        sfx[i] = max(cur, sfx[i+1]);
    }

    // for(int i = 0; i < n; i++){
    //     cout << pfx[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << sfx[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, pfx[i] + sfx[i+1]);
    }
    cout << ans << endl;
}