#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN], cor[MAXN];

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    //v, gcd
    stack<int> st;
    int g; cin >> g;
    st.push(g);
    for(int i = 0; i < n-1; i++){
        int x; cin >> x;
        g = gcd(x, g);
        st.push(g);
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            auto g = st.top();
            int x; cin >> x;
            g = gcd(x, g);
            st.push(g);
        }else if(op == 2){
            int k; cin >> k;
            while(!st.empty() && k--) st.pop();
        }else{
            int x; cin >> x;
            auto g = st.top();
            if(!(g%x)) cout << "SIM\n";
            else cout << "NAO\n";
        }
    }
}
