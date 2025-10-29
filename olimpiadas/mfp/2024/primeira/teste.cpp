#include <bits/stdc++.h>
using namespace std; 

//1 2 3 4 5 6
//3 4 3 3 2 1
//6 5 3 4

int main(){
    int n; cin >> n;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++){
        auto it = st.find(i);
        if(it == st.end()) continue;
        ans.push_back(*it);
        st.erase(i);
    }

    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}