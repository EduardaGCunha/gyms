#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int n, m;
vector<int> casas, postes;

bool check(int r){
    int p = 0, c = 0;
    while(c < n && p < m){
        if(abs(casas[c] - postes[p]) <= r){
            c++;
        }else p++;
    }
    //cout << r << " " << c << endl;
    return (c == n);
}

signed main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        casas.push_back(x);
    }

    cin >> m;
    for(int i = 0; i < m; i ++){
        int  x; cin >> x;
        postes.push_back(x);
    }

    sort(casas.begin(), casas.end());
    sort(postes.begin(), postes.end());

    int l = 0, r = 1e18;
    while(l <= r){
        int mid = (l+r)/2;
        if(!check(mid)) l = mid+1;
        else r = mid-1;
    }
    cout << l << endl;
}