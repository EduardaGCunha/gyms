
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long

const int MAXN = 1e5+7;
vector<int> graph[MAXN], groups;

bool check(int x){
    int seg = 0, sum = 0;
    for(auto u : groups){
        if(u > (x-seg)) sum += (u - (x-seg));
        seg++;
    }
    x -= groups.size();
    return (x >= sum);
}


signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        graph[x].push_back(i);
    }

    for(int i = 0; i < n; i++){
        if(graph[i].size() == 0) continue;
        groups.push_back(graph[i].size());
    }

    groups.push_back(1);
    sort(groups.rbegin(), groups.rend());

    int l = 0, r = n, ans = 0;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << l << endl;
}