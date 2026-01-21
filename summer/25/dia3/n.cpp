#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'


signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%3) cout << "First\n";
        else cout << "Second\n";
    }
}