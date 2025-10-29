#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
set<int> x[MAXN], rx[MAXN], ry[MAXN], y[MAXN];
int dir = 0, n, m;

void solve(int &st, int &e){
    if(dir == 0){
        auto nxt = x[st].upper_bound(e);
        if(nxt == x[st].end()) e = m;
        else e = (*nxt)-1;
    }else if(dir == 1){
        auto nxt = y[e].upper_bound(st);
        if(nxt == y[e].end()) st = n;
        else st = (*nxt)-1;
    }else if(dir == 2){
        auto nxt = rx[st].upper_bound(-e);
        if(nxt == rx[st].end()) e = 1;
        else e = -(*nxt)+1;
    }else{
        auto nxt = ry[e].upper_bound(-st);
        if(nxt == ry[e].end()) st = 1;
        else st = -(*nxt)+1;
    }
}

int main(){
    int k, l, st, end;
    cin >> n >> m >> st >> end >> k >> l;
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        x[a].insert(b);
        rx[a].insert(-b);
        y[b].insert(a);
        ry[b].insert(-a);
    }

    //cout << "prints\n";
    //cout << st << " " << end << endl;
    for(int i = 0; i < l; i++){
        solve(st, end);
        //cout << st << " " << end << endl;
        dir = (dir+1)%4;
    }

    cout << st << " " << end << endl;

    
}