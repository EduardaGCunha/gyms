#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n+2];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    arr[n+1] = 0;
    int mx = 0;
    arr[0] = 0;
    stack<pair<int, int>> st;
    for(int i = 1; i <= n + 1; i++){
        int lst = i;
        while(!st.empty() && arr[i] < st.top().first){
            auto [h, idx] = st.top(); st.pop();
            mx = max(min(i-idx, h), mx);
            
            lst = idx;
        }

        if(st.empty() || arr[i] > st.top().first){
            st.push({arr[i], lst});
        }
    }

    cout << mx << endl;
}