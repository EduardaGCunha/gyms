#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MAXN = 2e3;
char cur[MAXN][MAXN], pre[MAXN][MAXN], base[MAXN][MAXN];
int n, m, k = 0; 

void cbase(int x, int y, int op){
    for(int i = x; i < n+x; i++){
        for(int j = y; j < n+y; j++){
            cur[i][j] = (op == 1 ? base[i-x][j-y] : '.');
        }
    }
}

void solve(int cnt){
    if(cnt == m-1) return;
    int x = 0; // y sai daqui
    for(int i = 0; i < k; i++){
        int y = 0; // y entra aqui para resetar a cada linha
        for(int j = 0; j < k; j++){
            if(pre[i][j] == '#') cbase(x, y, 1);
            else cbase(x, y, 0);
            y += n;
        }
        x += n;
    }
    k = x;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++) 
            pre[i][j] = cur[i][j];
    
    solve(cnt+1);
}

signed main(){
    fastio;
    cin >> n >> m;
    k = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> base[i][j];
            pre[i][j] = base[i][j];
            if(m ==1) cout << pre[i][j];
        }
        if(m==1)cout << endl;
    }
    if(m == 1) return 0;
    solve(0);
    //cout << k << endl;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cout << cur[i][j];
        }
        cout << endl;
    }
}