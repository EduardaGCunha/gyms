#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int n; cin >> n;
    stack<string> st;
    while(n--){
        char op; cin >> op;
        if(op == '?'){
            if(st.empty()) cout << "Backlog vazio\n";
            else{
                cout << st.top() << endl;
                st.pop();
            }
        }else{
            string s;
            getline(cin, s);
            s = s.substr(1);
            st.push(s);
        }
    }
}