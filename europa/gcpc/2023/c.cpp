#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

const int MAXN = 2e5+7;
const int INF = 1e9;
vector<int> graph[MAXN];
int dist[2][MAXN];
int n;

template<typename T = int> struct frac {
	T num, den;
	template<class U, class V>
	frac(U num_ = 0, V den_ = 1) : num(num_), den(den_) {
		assert(den != 0);
		if (den < 0) num *= -1, den *= -1;
		T g = gcd(abs(num), den);
		num /= g, den /= g;
	}
 
	friend ostream& operator<<(ostream& out, frac f) {
		out << f.num << '/' << f.den;
		return out;
	}
    friend bool operator<(const frac& l, const frac& r) {
		return l.num * r.den < r.num * l.den;
	}
	// friend frac operator=(const frac& l, const frac& r) {
	// 	return {r.num, r.den};
	// }
};

void dijsktra(int id, int st){
    for(int i = 1; i <= n; i++) dist[id][i] = INF;
    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    dist[id][st] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[id][v] < d) continue;
        for(auto u : graph[v]){
            if(dist[id][u] > dist[id][v] + 1){
                dist[id][u] = dist[id][v] + 1;
                pq.push({-dist[id][u], u});
            }
        }
    }

}
 

void solve(){
    int m, k; cin >> n >> m >> k;
    vector<int> tp(k);
    for(int i = 0; i < k; i++) cin >> tp[i];

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dijsktra(0, 1);
    dijsktra(1, n);

    int sums = 0;
    for(auto t : tp){
        sums += dist[1][t];
    }

    frac ans(INF, 1LL);

    for(auto t : tp){
        int v = dist[0][t]*(k-1) + (sums - dist[1][t]);
        frac nw(v, k-1);
        if(nw < ans) ans = nw;
    }

    frac sem(dist[0][n], 1LL);
    if(sem < ans) ans = sem;
    cout << ans << endl;
}

signed main(){
    int t = 1;
    while(t--) solve();
    return 0;
}
