#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

vector<pair<int, int>> init = {
    {1, 13},
    {1, 8},
    {1, 3},
    {4, 1},
    {9, 1},
    {14, 1}
};
//R, L, U, D
int d1[] = {0, 0, 1, -1};   
int d2[] = {1, -1, 0, 0};


void solve(){
  for(auto [a, b] : init){
    int pos = 0;
    while(a <= 14 && b <= 14){
        cout << "? " << a << " " << b << endl;
        string c; cin >> c;
        if(c == "BOOM") return;
        if(c == "A"){
            pos = 1;
            break;
        }
        a++, b++;
    }

    if(pos){
        vector<int> pos(4, 0);
        for(int i = 0; i < 4; i++){
            int dx = a + d1[i];
            int dy = b + d2[i];
            if(dx <= 0 || dx > 14) continue;
            if(dy <= 0 || dy > 14) continue;

            cout << "? " << dx << " " << dy << endl;
            string c; cin >> c;
            if(c == "E") continue;
            if(c == "BOOM") return;
            while(1){
                dx = dx + d1[i];
                dy = dy + d2[i];
                if(dx <= 0 || dx > 14) break;
                if(dy <= 0 || dy > 14) break;
                cout << "? " << dx << " " << dy << endl;
                string c; cin >> c;
                if(c == "BOOM") return;
                if(c == "E") break;
            }
        }
    }
  }
}

signed main() {
    //fastio;
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
