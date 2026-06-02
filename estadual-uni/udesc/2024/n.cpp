#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int n, m, q; cin >> n >> m >> q;
    vector<int> linha(max(n, m)+1, 0), coluna(max(n, m)+1, 0);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int a, b; cin >> a >> b;
            linha[a] = 1;
            coluna[b] = 1;
        }else{
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            if((linha[x1] || coluna[y1]) && (linha[x2] || coluna[y2])){
                cout << "SIM\n";
            }else cout << "NAO\n";
        }
    }
}
