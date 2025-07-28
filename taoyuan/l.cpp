#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 N;
    cin >> N;
    static const unordered_map<int, int> small_odd = {
        {11, 4},
        {13, 5},
        {15, 6},
        {17, 8},
        {19, 9},
        {21, 9},
        {23, 9},
        {25, 9},
        {27, 9},
    };

    int64 K;
    if (N < 9) {
        K = N;
    }
    else if ((N & 1) == 0) {
        K = N / 2;
    }
    else {
        if (N >= 29) {
            K = (N - 9) / 2;
        }
        else {
            auto it = small_odd.find((int)N);
            if (it != small_odd.end()) {
                K = it->second;
            } else {
                K = 0;
            }
        }
    }

    cout << (K % MOD) << "\n";
    return 0;
}
