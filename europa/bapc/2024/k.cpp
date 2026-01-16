#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

using namespace std;

const int MOD = 1e9+7;
const int MOD2 = 1e9+9;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct str_hash {
	static int P;
	vector<int> h, p;
	str_hash(string s) : h(s.size()), p(s.size()) {
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	int operator()(int l, int r) { // retorna hash s[l...r]
		int hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1);

signed main(){
    fastio;
    string s; cin >> s;
    int n = s.size();
    str_hash<MOD> h1(s);
    str_hash<MOD2> h2(s);
    int ans = 5005;
    for(int sz = 1; sz <= n; sz++){
        vector<pair<pair<int, int>, int>> v;
        for(int i = 0; i + sz <= n; i++){
            int hash = h1(i, i+sz-1);
            int hash2 = h2(i, i + sz-1);
            v.push_back({{hash, hash2}, i});
        }

        sort(v.begin(), v.end());
        int cnt = 0, lst = -1;
        for(int k = 0; k < v.size(); ){
            pair<int, int> h = v[k].first;
            int cnt = 0, lst = -1;
            while(k < v.size() && v[k].first == h){
                int idx = v[k].second;
                if(idx > lst){
                    lst = idx + sz - 1;
                    cnt++;
                }
                k++;
            }
            int newsize = (n - sz*cnt) + cnt + sz;
            ans = min(ans, newsize);
        }
    }

    cout << ans << endl;
}
