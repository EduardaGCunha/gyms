#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            string a = s.substr(0, i);
            string b = s.substr(i, j-i);
            string c = s.substr(j);
            
            vector<string> v = {a, b, c};
            sort(v.begin(), v.end());
            do {
                if(v[0] + v[1] + v[2] == t){
                    cout << "YES" << endl;
                    cout << a << " " << b << " " << c << endl;
                    cout << v[0] << " " << v[1] << " " << v[2] << endl;
                    return;
                }
            } while(next_permutation(v.begin(), v.end()));
        }
    }

    cout << "NO" << endl;
}

signed main() {
    fastio;
    solve();
    return 0;
}