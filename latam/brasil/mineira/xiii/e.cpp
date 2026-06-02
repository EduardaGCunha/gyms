#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e18;

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	int F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int t, int f = INF) {
		if (!f or v == t) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, t, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	int max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};


signed main(){
    fastio;
    int n, m; cin >> n >> m;
    dinitz flow1(n+2), flow2(n+2);
    for(int i = 0; i <m; i++){
        int a, b; cin >> a >> b;
        flow1.add(a, b, 1);
        flow1.add(b, a, 1);
        flow2.add(a, b, 1);
        flow2.add(b, a, 1);
    }
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

    int s = 0, t = n+1;
    flow1.add(s, a1, INF);
    flow1.add(s, b1, INF);

    flow1.add(a2, t, INF);
    flow1.add(b2, t, INF);

    flow2.add(s, a1, INF);
    flow2.add(s, b2, INF);

    flow2.add(a2, t, INF);
    flow2.add(b1, t, INF);

    int ans = min(flow1.max_flow(s, t), flow2.max_flow(s, t));

    cout << ans << endl;
}   
