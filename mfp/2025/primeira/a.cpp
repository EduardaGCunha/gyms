#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e5+7;
int cnt[MAXN], arr[MAXN];

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        cnt[a]++;
    }

    int suf = 0;
    for(int i = m; i >= 1; i--){
        suf += cnt[i];
        arr[i] = suf;
    }

    for(int i = 1; i <= m; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}
