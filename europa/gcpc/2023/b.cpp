#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

using namespace std;
struct pt {
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
	int operator * (const pt p) const { return x*(int)p.x + y*(int)p.y; }
	int operator ^ (const pt p) const { return x*(int)p.y - y*(int)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

int sarea2(pt p, pt q, pt r) {
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) {
	return sarea2(p, q, r) == 0;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


bool solve(vector<pt> v, int k){
    if(v.size() <= k) return true;

    if(k == 1){
        for(int i = 2; i < v.size(); i++){
            if(!col(v[0], v[1], v[i])) return false;
        }
        return true;
    }

    if(k == 0) return false;


    int t = 31;
    while(t--){
        int a = rng()%v.size();
        int b = rng()%v.size();
        while(a == b) b = rng()%v.size();

        pt x = v[a], y = v[b];

        vector<pt> nw;
        for(auto u : v){
            if(!col(x, y, u)) nw.push_back(u);
        }
        
        if(solve(nw, k-1)) return true;
    }

    return false;
}

signed main(){
    fastio;
    int n; cin >> n;
    vector<pt> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(solve(arr, 3)) cout << "possible\n";
    else cout << "impossible\n";
}
