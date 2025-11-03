#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use long long for distances to avoid overflow
using ll = long long;

// Adjacency list to store the tree: {neighbor, edge_length}
vector<pair<int, int>> adj[100005];
int n, k;

// Global variables for the check function
int stations_needed;
bool possible;

ll dfs(int u, int p, ll d_prime) {
    if (!possible) return 0; // If already impossible, stop early

    ll max1 = 0; // Largest farthest uncovered distance from a child
    ll max2 = 0; // Second largest

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int l = edge.second;
        if (v == p) continue;

        // --- Rule 1 Check ---
        // l > d'
        if (l > d_prime) {
            possible = false;
            return 0;
        }

        ll dist_from_child = dfs(v, u, d_prime);
        if (!possible) return 0; // Propagate impossibility

        // --- Rule 2 Check ---
        // dfs(u) + l > d' (where 'u' is the child 'v')
        if (dist_from_child + l > d_prime) {
            // "we should set a gas station at u" (at 'v' in our code)
            stations_needed++;
        } else {
            // This child's subtree has an uncovered node.
            // Track its distance from 'u'.
            ll current_dist = dist_from_child + l;
            if (current_dist > max1) {
                max2 = max1;
                max1 = current_dist;
            } else if (current_dist > max2) {
                max2 = current_dist;
            }
        }
    }

    // --- Rule 3 Check ---
    // ...two subtrees (u, lu), (v, lv) ... dfs(u)+lu+lv+dfs(v) > d'
    // This is equivalent to max1 + max2 > d'
    if (max1 + max2 > d_prime) {
        // "we should set a gas station at r" (at 'u' in our code)
        stations_needed++;
        return 0; // Station at 'u' covers all nodes in its subtree
    }

    // Pass up the farthest uncovered distance from this subtree
    return max1;
}

/**
 * Checks if it's possible to cover the tree with <= k stations
 * given a max distance d_prime.
 */
bool check(ll d_prime) {
    stations_needed = 0;
    possible = true;
    
    // Start DFS from the root (assuming node 0 is the root)
    ll farthest_from_root = dfs(0, -1, d_prime);

    if (!possible) return false;

    // If the root itself has an uncovered node, we must place one
    // final station at the root.
    if (farthest_from_root > 0) {
        stations_needed++;
    }

    return stations_needed <= k;
}

int main() {
    // Faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read problem input
    cin >> n >> k;

    ll sum_l = 0; // Sum of all edge lengths (for binary search upper bound)

    // Read n-1 edges
    for (int i = 0; i < n - 1; ++i) {
        // Assuming 1-based indexing for input, converting to 0-based
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--; 
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
        sum_l += l;
    }

    // Binary search for the minimal d'
    ll low = 0;
    ll high = sum_l;
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            // This d' (mid) works, try for an even smaller one
            ans = mid;
            high = mid - 1;
        } else {
            // This d' (mid) was too small, need a larger distance
            low = mid + 1;
        }
    }

    // Print the minimal d' that works
    cout << ans << endl;

    return 0;
}