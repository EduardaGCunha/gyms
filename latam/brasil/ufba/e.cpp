#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


signed main(){
    fastio;
    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;

    int ans = abs(ax-bx) + abs(ay-by);

    int n; cin >> n;
    int best = 0;
    for(int i = 0; i < n; i++){
        int k, dir; cin >> k >> dir;
        int intersec;
        if(dir == -1){ 
            if(ax > bx && ay < by){
                int intersec = min(ax, k - ay) - max(bx, k - by);
                best = max(best, max(0LL, intersec));
            }
            if(ax < bx && ay > by){
                int intersec = min(bx, k - by) - max(ax, k - ay);
                best = max(best, max(0LL, intersec));
            }
        } 
        else{ 
            if(ax < bx && ay < by){
                int intersec = min(bx, by - k) - max(ax, ay - k);
                best = max(best, max(0LL, intersec));
            }
            if(ax > bx && ay > by){
                int intersec = min(ax, ay - k) - max(bx, by - k);
                best = max(best, max(0LL, intersec));                
            }
        }
        
    }

    cout << ans - best << endl;
}
