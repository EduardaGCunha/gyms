#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

#define sq(x) ((x)*(ll)(x))

const int MOD = 998244353;

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};


ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

const int INF = 1e18;

void solve(){
    int n; cin >> n;
    vector<pt> v;
    for(int i = 0; i < n; i++){
        pt x; cin >> x;
        v.push_back(x);
    }

    int tot = (1 << n);
    vector<int> dp(tot+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int msk = 1<<i;
        dp[msk] = 1;
        for(int j = i+1; j < n; j++){
            dp[msk | (1<<j)] = 1;
        }
    }

    for(int mask = 0; mask < tot; mask++){
        if(dp[mask] == INF) continue;
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(!((1<<i)&mask)){
                idx = i;
                break;
            }
        }

        if(idx==-1) break;
        //manter do jeito q ta ou manter sozinho
        dp[mask | (1<<idx)] = min(dp[mask | (1<<idx)], dp[mask] + 1);

        for(int i = 0; i < n; i++){
            if(i == idx) continue;
            int sub = (1<<i) | (1<<idx);
            for(int j = 0; j < n; j++){
                if(j == idx || j == i) continue;
                if(col(v[idx], v[i], v[j])) sub |= (1<<j);
            }
            dp[mask | sub] = min(dp[mask | sub], dp[mask] + 1);
        }

    }

    cout << dp[tot-1] << endl;
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}