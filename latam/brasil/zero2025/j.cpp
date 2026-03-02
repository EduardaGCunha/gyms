#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int arr[2*n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i+n] = arr[i];
    }

    stack<int> st;
    int ans[2*n];
    for(int i = 1; i <= 2*n; i++){
        while(!st.empty() && arr[st.top()] + (i - st.top())*k > arr[i]){
            int idx = i;
            if(i > n) idx = i - n;
            ans[st.top()] = idx;
            st.pop();
        }
        st.push(i);
    }

    for(int i = 1; i <= n; i++){
        //if(ans[i] > n) ans[i] -= n;
        cout << ans[i] << " ";
    }
    cout << endl;
}