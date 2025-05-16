#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int arr[n];
    priority_queue<int> pq;
    int t=k;
    int idx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(t){
            pq.push(-arr[i]);
            t--;
            if(t == 0){
                idx = (i+1 < n ? i+1 : n-1);
            }
        }
    }

    int curtime = 0, ans = 0;
    while(!pq.empty()){
        int u = -pq.top(); pq.pop();
        curtime += u;
        ans += curtime;
        if(idx < n){
            pq.push(-arr[idx]);
            idx++;
        }
    }
    cout << ans << endl;
}