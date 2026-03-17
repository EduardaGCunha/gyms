#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

using namespace std;

const int INF = 1e9;

#define ld long double

signed main(){
    fastio;
    string s; cin >> s;
    int mx = 1000;
    string t ="";
    vector<ld> pref(min(mx, (int) s.size()));
    for(int i = 0; i < min(mx, (int)s.size()); i++){
        t += s[i];
        ld v = 0;
        ld pot = 1;
        ld k = t.size();
        for(int j = k-1; j >= 0; j--){
            v += (t[j]-'0')*pot;
            pot = pot*10;
        }
        pref[i] = v;
    }

    ld ans = (pref[0]*0.9);
    int sz = pref.size();
    ld val = 0.1;
    for(int i = 1; i < pref.size()-1; i++){
        ans += (pref[i]*val*(0.9));
        val = (val*0.1);
    }
    ans += (pref[sz-1]*val);
    cout << fixed << setprecision(10) << ans << endl;

}
