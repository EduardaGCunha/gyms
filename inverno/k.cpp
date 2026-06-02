#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int n, k, t;
vector<int> arr, fim;

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.resize(n+1, 0);
    }

    void upd(int x, int v){
        x++;
        for(; x <= n; x+=x&(-x)) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        x++;
        for(; x > 0; x -= x&(-x)) s += bit[x];
        return s;
    }

    int query(int r){
        return sum(r);
    }
};

int gety(int x){
    int val = lower_bound(fim.begin(), fim.end(), x) - fim.begin();
    return val;
}

/*
coloco como -1 todos que forem maior
*/

bool check(int mid){
    BIT bit;
    bit.init(2*n + 7); 
    bit.upd(0+n+1, 1);
    int sum =0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += (arr[i] >= mid ? 1 : -1);

        ans += bit.query(sum-1 + n+1);

        bit.upd(sum+n+1, 1);
    }
    return ans >= t;
}

signed main(){
    fastio;
    cin >> n >> k;
    arr.resize(n);
    vector<int> brr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        brr[i] = arr[i];
    }

    sort(brr.begin(), brr.end());
    brr.erase(unique(brr.begin(), brr.end()), brr.end());
    
    int l = 0, r = brr.size()-1;
    int ans = brr[0];
    t = n*(n+1)/2 - k + 1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(brr[mid])){
            l = mid+1;
            ans =brr[mid];
        }
        else r = mid-1;
    }
    cout << ans << endl;
}   
