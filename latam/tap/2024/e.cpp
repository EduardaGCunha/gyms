#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

struct val{
    int a, b, c; 
    bool operator<(const val &other){
        return b + a*other.b < other.b + (other.a)*b;
    }
};

signed main(){
    fastio;
    int n, P; cin >> n >> P;
    vector<val> v;
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    sort(v.begin(), v.end());

    vector<int> dp(P+7, 0);
    //passando dos maiores para os menores pq eles vao aparecer mais vezes
    for(int i = n-1; i >= 0; i--){
        auto [a, b, c] = v[i];
        for(int p = P; p >= b; p--){
            dp[p] = max(dp[p], dp[(p-b)/a] + c);
        }
    }

    cout << dp[P] << endl;
}