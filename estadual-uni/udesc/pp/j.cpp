#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*

*/

signed main() {
    fastio;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int i = 0, cnt = 0;
    for(; i < n; i++){
        if(s[i] == 'o') {
            cnt++;
            continue;
        }
        if(!k) break;
        k--;
    }
    int pos = 1;
    //cout << i << endl;
    if(i == n){
        s[i-1] = '#';
        i-=2;
    }
    for(; i >= 0; i--){
        if(cnt){
            s[i] = 'o';
            cnt--;
        }
        else if(!cnt && pos){
            s[i] = '#';
            pos = 0;
        }else s[i] = '.';
    }
    cout << s << endl;
}