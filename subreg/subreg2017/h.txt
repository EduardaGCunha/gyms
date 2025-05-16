#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define sq(x) ((x)*(ll)(x))
#define int long long

struct pt { // ponto
    int x, y, idx;
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
    int operator * (const pt p) const { return x*(int)p.x + y*(int)p.y; }
    int operator ^ (const pt p) const { return x*(int)p.y - y*(int)p.x; }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
    friend ostream& operator << (ostream& out, const pt& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }   
};

struct line { // reta
    pt p, q;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
    friend istream& operator >> (istream& in, line& r) {
        return in >> r.p >> r.q;
    }
};

int sarea2(pt p, pt q, pt r) { // 2 * area com sinal
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
    return sarea2(p, q, r) > 0;
}

const int MAXN = 100;
vector<int> graph[MAXN];
int indeg[MAXN];
int ans = 0;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b; 
    cin >> n >> a >> b;

    vector<pt> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
    }

    for(auto u : v){
        for(auto j : v){
            if(j == u) continue;
            if(ccw(u, a, j) && ccw(u, j, b)){
                graph[j.idx].push_back(u.idx);
                indeg[u.idx]++;
            }
        }
    }

	stack<int> st;
	vector<int> dist(n, -1);
    for(int i = 0; i < n; i++){
		if(!indeg[i]){
			st.push(i);
			dist[i] = 1;
		}
	}

	while(!st.empty()){
		auto v = st.top(); st.pop();
		for(auto u : graph[v]){
			if(dist[u] < dist[v]+1){
				dist[u] = dist[v]+1;
				st.push(u);
			}
		}
	}

	for(int i = 0; i < n; i++) ans = max(ans, dist[i]);
    cout << ans << endl;
    return 0;
}
