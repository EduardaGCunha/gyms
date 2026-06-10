#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN], parent[MAXN];

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    int ans1= 0, ans2 = 0;
    for(int i = 0; i < n; i+=2) ans1 += v[i];
    for(int i = 1; i < n; i+=2) ans2 += v[i];
    if(ans1 > ans2) cout << "Tourist\n";
    else cout << "Bald\n";
}   
