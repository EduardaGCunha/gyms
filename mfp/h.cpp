#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    priority_queue<int> pq;
    int c = 0;
    vector<pair<int, int>> sweep;
    for(int i = 0; i < n; i++){
        if(c < k){
            sweep.push_back({v[i].first, v[i].first + v[i].second});
            pq.push(-(v[i].first + v[i].second));
            c++;
        }
        else{
            int proxfinal = -pq.top(); pq.pop();
            if(proxfinal > v[i].first){
                //cout << proxfinal << " " << v[i].first << " " << v[i].second + v[i].first << endl;
                int finish = v[i].second + proxfinal;
                sweep.push_back({v[i].first, finish});
                pq.push(-finish);
            }else{
                //cout << proxfinal << " " << v[i].first << " " << v[i].second + v[i].first << endl;
                int finish = v[i].first + v[i].second;
                sweep.push_back({v[i].first, finish});
                pq.push(-finish);
            }
        }
    }
    vector<pair<int, int>> events;
    for(auto u : sweep){
        events.push_back({u.first, 1});
        events.push_back({u.second, -1});
    }
    sort(events.begin(), events.end());
    int ans = 0, cur = 0;
    for(auto u : events){
        cur += u.second;
        ans = max(ans, cur);
    }
    cout << ans << endl;

}