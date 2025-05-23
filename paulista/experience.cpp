#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 3*(1e5)+7;
int p[MAXN], r[MAXN], xp[MAXN], n, m;

void init(){
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
}

int get(int a){
    return (p[a] == a ? a : (get(p[a])));
}

int total(int a){
    int ans = xp[a];
    while(a != p[a]){
        ans += xp[p[a]];
        a = p[a];
    }
    return ans;
}

void unite(int a, int b){
    int x = get(a), y = get(b);
    if(x == y) return;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]){
        p[y] = x;
        r[x]++;
        xp[y] -= xp[x];
    }else{
        p[x] = y;
        r[y]++;
        xp[x] -= xp[y];
    }
    //cout << xp[x] << " " << xp[y] << endl;
}


signed main(){
    fastio;
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        string a;
        cin >> a;
        if(a == "add"){
            int b, c; cin >> b >> c;
            b = get(b);
            xp[b] += c;
        }else if(a == "join"){
            int b, c; cin >> b >> c;
            unite(b, c);
        }else{
            int b; cin >> b;
            cout << total(b) << endl;
        }

    } 
}