#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+7;

int primo[MAXN];
void crivo(){
    for(int i = 2; i < MAXN; i++) primo[i] = 1;
    for(int i = 2; i*i < MAXN; i++){
        if(!primo[i]) continue;
        for(int j = i*i; j < MAXN; j += i){
            primo[j] = 0;
        } 
    }
}

signed main() {
    fastio;
    crivo();
    int n; cin >> n;
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(primo[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}