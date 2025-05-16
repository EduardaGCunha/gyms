#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int MAXN = 1e5+7;
int bit[MAXN], cam[MAXN];

int n;
void upd(int x, int v){
    for(; x <= n; x += (x&-x)) bit[x] += v;
}

int soma(int x){
    int res = 0;
    for(; x > 0; x -= (x&-x)) res += bit[x];
    return res;
}

int main(){
    fastio;
    int k, r;
    cin >> n >> k >> r;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        upd(x, 1);
        cam[x] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= n - r + 1; i++){
        int j = i + r - 1;
        int sum = soma(j) - soma(i-1);
        int cur= max(0, 2 - sum);
        int pos = j;
        while(cur > 0 && pos >= i){
            if(!cam[pos]){
                cam[pos] = 1;
                upd(pos, 1);
                ans++;
                cur--;
            }
            pos--;
        }
    }

    cout << ans << endl;
}