#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    int n; cin >> n;
    while(n--){
        int a, b, c; cin >> a >> b >> c;
        vector<int> visited(7, 0);
        visited[a] = 1;
        visited[b] = 1;
        visited[c] = 1;
        int sum =0;
        for(int i = 1; i <= 6; i++){
            if(!visited[i]) sum += i;
        }
        cout << sum << endl;
    }
}