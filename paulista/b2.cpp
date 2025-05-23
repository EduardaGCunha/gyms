#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 1e5;
vector<pair<int, int>> graph[MAXN];
int dist[2][MAXN];
int n;

// c == 0 -> Carlos, c == 1 -> people
int check(int c, vector<pair<int, int>> caras) {
    // initialize appropriate dist array
    fill(dist[c], dist[c] + n, INF);
    // priority_queue stores (-time, node)
    priority_queue<pair<int, int>> pq;

    for (auto &u : caras) {
        int init_time = (c == 1 ? u.first : -u.first);
        dist[c][u.second] = init_time;
        pq.push({ -init_time, u.second });
    }

    while (!pq.empty()) {
        auto [negd, v] = pq.top(); pq.pop();
        int d = -negd;
        if (d != dist[c][v]) continue;

        for (auto &e : graph[v]) {
            int u = e.first;
            int w = e.second;
            int nd = d + (c == 1 ? 2 * w : w);
            if (nd < dist[c][u]) {
                // if Carlos, block nodes where people arrive earlier
                if (c == 0 && nd > dist[1][u]) continue;
                dist[c][u] = nd;
                pq.push({ -nd, u });
            }
        }
    }

    // only Carlos uses this result: check if reached n-1
    if (c == 0)
        return dist[0][n-1] < INF;
    else
        return dist[0][n-1] < INF; // dummy, not used for people
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    vector<pair<int, int>> entradas;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        --x;
        entradas.push_back({ 0, x });
    }

    // first, run people Dijkstra
    check(1, entradas);

    // now binary search Carlos' start time
    int l = 0, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<pair<int, int>> caras = { { mid, 0 } };
        if (check(0, caras)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
