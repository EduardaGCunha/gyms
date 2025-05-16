

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
const int INF = LLONG_MIN / 4;

const int MAXN = 2*(1e5);
int n, k;
vector<int> x;                         
vector<int> graph[MAXN];       

vector<int> dfs(int v) {
    vector<int> dp(1, 0);
    for (int u : graph[v]) {
        vector<int> cd = dfs(u);
        
        if (dp.size() < cd.size()) dp.swap(cd);

        int sv = dp.size() - 1;
        int su = cd.size() - 1;
        int new_max = min(k, sv + su);
        vector<int> nd(new_max + 1, INF);

        for (int i = 0; i <= sv; i++) {
            if (dp[i] <= INF) continue;
            for (int j = 0; j <= su && i + j <= k; j++) {
                if (cd[j] <= INF) continue;
                nd[i + j] = max(nd[i + j], dp[i] + cd[j]);
            }
        }
        dp.swap(nd);
    }

    if (v != 1) {
        if (dp.size() < 2) dp.resize(2, INF);
        dp[1] = max(dp[1], x[v]);
    }

    if ((int)dp.size() > k + 1) dp.resize(k + 1);
    return dp;
}

signed main() {
    cin >> n >> k;
    x.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        graph[p].push_back(i);
    }

    vector<int> root_dp = dfs(1);
    int ans = 0;
    if (k < (int)root_dp.size() && root_dp[k] > 0)
        ans = root_dp[k];
    cout << ans << "\n";
    return 0;
}
