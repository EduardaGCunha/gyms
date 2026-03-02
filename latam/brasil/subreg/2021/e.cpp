#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<int> dir, esq;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        if(b) dir.push_back(a);
        else esq.push_back(a);
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    int l = 0, r = 0, ans = 0;
    while(!q.empty()){
        auto [v, d] = q.front(); q.pop();
        if(d){
            if(r + 1 < dir.size() && dir[r+1] <= v + 10){
                r++;
                q.push({dir[r], 1});
            }else {
                ans = v + 10;
                if(l + 1 < esq.size()){
                    l++;
                    q.push({esq[l+1], 0});
                }
            }
        }else{
            cout << "entrou aq valores: " << v << " "; 
            if(l + 1 <= esq.size() && esq[l+1] <= (v + 10)){
                l++;
                q.push({esq[l], 0});
            }else {
                ans = v + 10;
                if(r + 1 < dir.size()){
                    r++;
                    q.push({dir[r], 1});
                }
            }
        }
    }
    cout << endl;
    cout << ans << endl;
}