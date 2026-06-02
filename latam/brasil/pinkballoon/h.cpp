#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int n; cin >> n;
    set<pair<int, string>> st;
    for(int i = 0; i < n; i++){
        int a;
        string b;
        cin >> a >> b;
        st.insert({a, b});
    }

    cout << st.size() << endl;
}