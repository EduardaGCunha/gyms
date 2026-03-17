#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

signed main(){
    fastio;
    int n; cin >> n;
    map<int, vector<int>> pos;
    vector<int> intersection(n, 0);
    vector<int> shared(n, -1);
    vector<int> active;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            for(auto other : pos[x]){
                if(intersection[other] == 0){
                    active.push_back(other);
                    shared[other] = x;
                }else if(intersection[other] == 1){
                    cout << shared[other] << " " << x << " " << i+1 << " " << other+1 << endl;
                    return 0;
                }
                intersection[other]++;
            }
            pos[x].push_back(i);
        }
        for(auto u : active){
            shared[u] = -1;
            intersection[u] = 0;
        }
        active.clear();
    }

    cout << "impossible\n";

}