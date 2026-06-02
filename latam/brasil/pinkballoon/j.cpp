#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
efetivamente so eh possivel fazer 26 rotacoes para esquerda ou direita
*/

signed main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int ans = INT_MAX;
    if(s == t){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        string k = s.substr(0, i);
        string l = s.substr(i, n);
        //cout << k << " " << l << " ";
        string fim = l + k;
        int sum = min(i, n-i);
        //cout << fim << " " << sum << endl;
        for(int j = 0; j < n; j++){
            int v = abs(fim[j]-t[j]);
            int v2;
            if(fim[j] > t[j]) v2 = 26 - (fim[j]-'a') + (t[j]-'a');
            else  v2 = 26 - (t[j]-'a') + (fim[j]-'a');
            sum += min(v, v2);
            //cout << v << " " << v2 << " " << sum << endl;
        }
        ans = min(ans, sum);
        //cout << fim << endl;
    }
    
    cout << ans << endl;
}