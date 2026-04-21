#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<int> st;
    int ans = 0;
    st.insert(0);
    st.insert(n+1);
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '1'){
            int pr = *(prev(st.lower_bound(i)));
            ans += (i-pr)*(n-i+1);
            st.insert(i);
        }
    }
    
    //cout << ans << endl;

    int q; cin >> q;
    while(q--){
        int pos;
        char c; cin >> pos >> c;
        if(s[pos-1] == c){
            cout << ans << endl;
            continue;
        }
        s[pos-1] = c;
        int v = c - '0';
        if(v == 0){
            
            auto it = st.lower_bound(pos);
            int pr = abs(pos - *(prev(it)));
            int nxt = abs(pos - *(next(it)));
            int cal = pr * nxt;
            ans -= cal;
            st.erase(it);
        }else{
            st.insert(pos);
            auto it = st.lower_bound(pos);
            int pr = abs(pos - *(prev(it)));
            int nxt = abs(pos - *(next(it)));
            int cal = pr*nxt;
            ans += cal;
        }
        cout << ans << endl;
    }
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}