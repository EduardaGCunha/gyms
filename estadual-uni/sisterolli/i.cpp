#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long

const int INF = 1e18;

signed main(){
    int n; cin >> n;
    vector<int> arr;
    int prev = INF, lucro = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        //cout << x -prev << " " << lucro << endl;
        if(x-prev > lucro){
            lucro = x-prev;
        }
        prev = min(x, prev);
    }

    cout << lucro << endl;
}