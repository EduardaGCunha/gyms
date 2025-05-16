#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main(){
    fastio;
    int n, p, k; cin >> n >> p >> k;
    vector<int> pessoas;
    for(int i = 1; i <= n; i++){
        if(i == p) continue;
        pessoas.push_back(i);
    }

    int next = (p%n) + 1;
    auto it = find(pessoas.begin(), pessoas.end(), next);
    int st = distance(pessoas.begin(), it); 
    int ans = (st + k) % pessoas.size();
    cout << pessoas[ans] << endl;
    
}
