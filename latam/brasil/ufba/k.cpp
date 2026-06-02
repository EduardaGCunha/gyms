#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int n, k;
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
    bit.init(fim.size());
    bit.upd(gety(0), 1);
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        int q = upper_bound(fim.begin(), fim.end(), sum-mid) - fim.begin();
        cnt += bit.query(q-1);
        bit.upd(gety(sum), 1);
    }
    return (cnt >= k);
}

signed main(){
    fastio;
    cin >> n >> k;
    arr.resize(n);
    vector<int> pref(n+1, 0);
    fim.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pref[i+1] = pref[i] + arr[i];
        fim.push_back(pref[i+1]);
    }


    sort(fim.begin(), fim.end());
    fim.erase(unique(fim.begin(), fim.end()), fim.end());
    
    int l = -2e14, r = 2e14;
    int ans = l;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            ans =mid;
        }
        else r = mid-1;
    }
    cout << ans << endl;
}   
