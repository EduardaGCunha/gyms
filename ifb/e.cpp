#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2*(1e5)+7;

signed main() {
    fastio;
    int n,m;
    cin>>n>>m;
    set<int> ans;
    for (int i = 0;i < n; i++){
        int a;
        cin >> a;
        ans.insert(a);
    }
    for (int i = 0;i < m; i++){
        int a;
        cin >> a;
        ans.insert(a);
    }
    for(auto u : ans) cout << u << " ";
}