#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int sum = 0;
    for(int i = 0; i < m; i++) sum += arr[i];

    if(sum > k) cout << "Nao e possivel\n";
    else cout << sum << endl;

}

signed main(){
	fastio;
    int t;
    t = 1;
	while(t--){
		solve();
	}
}