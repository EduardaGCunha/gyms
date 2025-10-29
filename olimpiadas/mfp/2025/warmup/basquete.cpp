#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main(){
    int n; cin >> n;
    int time1 = 0, time2 = 0, k;
    string s;
    while(n--){
        cin >> s >> s >> k;
        if(s == "1") time1 += k;
        else time2 += k;
    }
    cout << time1 << " x " << time2 << endl;
}