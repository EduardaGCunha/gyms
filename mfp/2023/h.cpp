#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = (5*1e5);
int arr[MAXN], sums[MAXN];
unordered_map<int, int> mp;
int n, pos = 0;

/*
tenho o cara inicial e o final 
soma total - v.back() -> tem q existir esse valor no map
*/

bool construct(int x){
    auto cnt = mp;
    vector<int> v;
    if(--cnt[x] < 0) return false; 
    v.push_back(x);
    int cur = x;
    for(int i = 0; i < n-1; i++){
        int nxt = sums[i] - cur;
        if(cnt[nxt]-- <= 0) return false;
        v.push_back(nxt);
        cur = nxt;
    }
    for(auto u : v){
        cout << u << " ";
    }
    cout << endl;
    return true;
}

signed main(){
    fastio;
    cin >> n;
    int tot = 0, overflowing = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tot += arr[i];
        mp[arr[i]]++;
    }
    for(int i = 0; i < n-1; i++){
        cin >> sums[i];
        overflowing += sums[i];
    }


    int p0p5 = tot - (overflowing - tot);
    sort(arr, arr+n);


    vector<int> cand = {arr[0], p0p5 - arr[0], arr[n-1], p0p5 - arr[n-1]};
    for(int x : cand){
        if(construct(x))
            break;
    }
    return 0;
}
