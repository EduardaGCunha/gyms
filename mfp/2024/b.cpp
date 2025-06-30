#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 5*1e4+7;
vector<int> graph[MAXN];
int values[MAXN];
int n, m, k = 0;
int dfs(int v, int p, int x){
    int sum = values[v];
    vector<int> sums;
    for(auto u : graph[v]){
        if(u == p) continue;
        int s = dfs(u, v, x);
        sums.push_back(s);
    }
    sort(sums.begin(), sums.end());
    for(auto s : sums){
        if(sum + s > x){
            k++;
        }else sum += s;
    }
    return sum;
}

bool check(int mid){
    k = 0;
    int root = dfs(0, 0, mid);
    if(root > mid) return false;
    return k <= m;
}

vector<pair<int, int>> ans;

int achar(int v, int p, int mx){
    int sum = values[v];
    vector<pair<int, int>> sums;
    for(auto u : graph[v]){
        if(u == p) continue;
        int s = achar(u, v, mx);
        sums.push_back({s, u});
    }

    sort(sums.begin(), sums.end());
    for(auto [s, u] : sums){
        if(sum + s > mx){
            k++;
            ans.push_back({v, u});
        }else sum += s;
    }
    return sum;
    
    return sum; 
}

void solve(){
    cin >> n >> m;
    int mx = 0, tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> values[i];
        mx = max(values[i], mx);
        tot += values[i];
    }
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int l = mx, r = tot, op = 0;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(check(mid)){
            op = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    //cout << l << endl;
    achar(0, 0, op);
    cout << ans.size() << endl;
    for(auto [a, b]: ans){
        cout << a+1 << " " << b+1 << endl;
    }
}


signed main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}