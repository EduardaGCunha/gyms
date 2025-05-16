#include <bits/stdc++.h>
using namespace std;


#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long


int mdc(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    if(a%b == 0) return b;
    return mdc(b, a%b);
}

struct gear{
    int x, y, r;
};

const int MAXN = 1e5+4;
vector<gear> v;
vector<int> graph[MAXN], c;
int visited[MAXN], n;

bool bfs(){
    queue<int> q; 
    q.push(0);
    visited[0] = 1;
    c.assign(n, 1);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u : graph[v]){
            if(visited[u]){
                if(c[u] == c[v]) return false;
                continue;
            }
            visited[u] = 1;
            c[u] = -c[v];
            q.push(u);
        }
    }
    return true;
}

signed main(){
    fastio;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        gear a; cin >> a.x >> a.y >> a.r;
        v.push_back(a);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if((v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y) != (v[i].r+v[j].r)*(v[i].r+v[j].r)) continue;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }

    if(!bfs()){
        cout << "The input gear cannot move.\n";
    }else if(!visited[n-1]){
        cout << "The input gear is not connected to the output gear.\n";
    }else{
        cout << c[n-1]*(v[0].r/mdc(v[0].r, v[n-1].r)) << ":" << v[n-1].r/mdc(v[0].r, v[n-1].r) << endl;
    }
}