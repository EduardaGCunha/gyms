#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long

const int INF = 1e18;

pair<int, int> op(char s, int x, int y){
    if(s == 'E') x--;
    else if(s == 'D') x++;
    else if(s == 'F') y++;
    else y--;
    return {x, y};
}

signed main(){
    int n; cin >> n;
    map<pair<int, int>, int> buraco;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        buraco[{x, y}]++;
    }

    string s; cin >> s;
    int x = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
        auto [dx, dy] = op(s[i], x, y);
        if(dx < 0 || dx >= 100) continue;
        if(dy < 0 || dy >= 100) continue;
        if(buraco[{dx, dy}] > 0) continue;
        x = dx;
        y = dy;
    }

    cout << x << " " << y << endl;
}