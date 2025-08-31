#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+7;
int d[MAXN];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        d[x] = 1;
    }

    int ans = 0, cnt = 0;
    for(int i = 0; i < MAXN; i++){
        if(!d[i]) cnt = 0;
        else cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}