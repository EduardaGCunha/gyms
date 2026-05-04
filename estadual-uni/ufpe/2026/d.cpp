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

const int MAXN = 5e5+7;
int dp[MAXN];

void solve(){
    int los = 1;
    dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= MAXN; i++){
        int mx = i/2;
        if(i - mx <= los) dp[i] = 1;
        else{
            dp[i] = 0;
            los = i;
        }
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    solve();
    while(t--){
        int n; cin >> n;
        if(dp[n+1]) cout << "mastermei\n";
        else cout << "the greatest\n";
    }
}