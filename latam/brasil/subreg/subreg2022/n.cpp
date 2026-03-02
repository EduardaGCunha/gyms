#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    int K, L;
    cin >> K >> L;

    // If K == N, take all cards, just pick top L B's to flip.
    if (K == N) {
        ll sumA = accumulate(A.begin(), A.end(), 0LL);
        vector<ll> Bs = B;
        nth_element(Bs.begin(), Bs.begin() + L, Bs.end(), greater<ll>());
        ll sumB = accumulate(Bs.begin(), Bs.begin() + L, 0LL);
        cout << (sumA + sumB) << "\n";
        return 0;
    }

    // Multisets to maintain top-L B's sum dynamically
    multiset<ll> top, bot;
    ll sumTop = 0;
    auto insertValue = [&](ll x) {
        if ((int)top.size() < L) {
            top.insert(x);
            sumTop += x;
        } else {
            auto it = top.begin(); // smallest in top
            if (x > *it) {
                ll y = *it;
                top.erase(it);
                sumTop -= y;
                bot.insert(y);
                top.insert(x);
                sumTop += x;
            } else {
                bot.insert(x);
            }
        }
    };
    auto removeValue = [&](ll x) {
        auto itBot = bot.find(x);
        if (itBot != bot.end()) {
            bot.erase(itBot);
        } else {
            auto itTop = top.find(x);
            top.erase(itTop);
            sumTop -= x;
            // rebalance: move largest from bot into top
            if (!bot.empty()) {
                auto it2 = prev(bot.end());
                ll y = *it2;
                bot.erase(it2);
                top.insert(y);
                sumTop += y;
            }
        }
    };

    // Initialize with first K cards: indices [0..K-1]
    ll sumA = 0;
    for (int i = 0; i < K; i++) {
        sumA += A[i];
        insertValue(B[i]);
    }

    ll ans = LLONG_MIN;
    // Enumerate i = number taken from left
    for (int i = K; i >= 0; i--) {
        // current pool: i leftmost removed are indices [0..i-1], rightmost removed are those added
        ans = max(ans, sumA + sumTop);
        if (i > 0) {
            int removeIdx = i - 1;
            int addIdx = N - K + i - 1;
            // update A-sum
            sumA -= A[removeIdx];
            sumA += A[addIdx];
            // update B-pools
            removeValue(B[removeIdx]);
            insertValue(B[addIdx]);
        }
    }

    cout << ans << "\n";
    return 0;
}
