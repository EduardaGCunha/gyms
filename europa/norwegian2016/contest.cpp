#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    
    int t = k;
    int idx = 0;
    priority_queue<int> pq;
    int arr[n];
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


    int time = 0, ans = 0;
    while(!pq.empty()){
        int u = -pq.top(); pq.pop();
        time += u;
        ans += time;
        if(idx < n){
            pq.push(-arr[idx]);
            idx++;
        }
    }
    cout << ans << endl;

    
}