#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

bool helper(int x){
    cout << "? " << x << endl;
    int res; cin >> res;
    return (res==1);
}

signed main() {
    int n; cin >> n;

    vector<int> path;
    int cur = 1, nivel = 1;
    path.push_back(1);
    while(nivel != n+1){
        int nxt = cur + nivel;
        int nxt2 = cur + nivel + 1;
        if(helper(nxt)){
            path.push_back(nxt);
            cur = nxt;
        }else{
            path.push_back(nxt2);
            cur = nxt2;
        }
        nivel++;
    }
    path.push_back(cur+nivel);
    int l = 0, r = path.size()-1;
    while(r - l > 1){
        int mid = l + (r-l)/2;
        if(helper(path[mid])){
            l = mid;
        }else r = mid;
    }

    cout << "! " << path[l] << endl;

}