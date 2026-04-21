#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 2e5+9;
int depositos[MAXN], cap[MAXN], arr[MAXN];
int n, k;

int check(int mid){
    //p cada deposito
    int p = 0;
    for(int i = 0; i < k; i++){
        if(p == n) continue;
        int cnt = 0;
        while(p < n && abs(depositos[i]-arr[p]) <= mid && cnt < cap[i]){
            cnt++;
            p++;
        }
    }
    return (p == n);
}

signed main(){
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    vector<pair<int, int>> d;
    vector<int> c(n);
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        d.push_back({x, i});
    }
    for(int i = 0; i < k; i++) cin >> c[i];
    sort(d.begin(), d.end());
    for(int i = 0; i < k; i++){
        depositos[i] = d[i].first;
        cap[i] = c[d[i].second];
    }

    int l = 0, r = 3e18, ans = 0;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << ans << endl;
}