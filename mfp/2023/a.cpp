#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 103;
int arr[MAXN], cnt = 0;
void dfs(int v, int og){
    if(v == og && cnt) return;
    cout << v+1 << " ";
    if(v == og && !cnt) cnt++;
    dfs(arr[v], og);
}

void solve(){
    //cout << "solve hiii\n";
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        arr[i] = x;
    }

    //cout << "passou da leitura\n";
    for(int i = 0; i < n; i++){
        dfs(i, i);
        cnt = 0;
        cout << endl;
    }
}

signed main() {
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}