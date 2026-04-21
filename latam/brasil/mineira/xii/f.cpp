#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MOD = 998244353;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
const int MAXN = 1e6+7;
int fat[MAXN], inv[MAXN];

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b = b>>1;
    }
    return res;
}

int comb(int n, int k){
    if (k < 0 || k > n) return 0;
    return ((fat[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int mx = n*m+7;
    fat[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fat[i] = (fat[i-1]*i)%MOD;
        inv[i] = fastexpo(fat[i], MOD-2);
    }

    char grid[n][m];
    int a = -1, b = -1;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j];
            if(s[j] == 'R') a = i, b = j;
        }
    }

    //flood fill
    queue<tuple<int, int, int>> q;
    //extra representa quantos queijos ja tem la naquela posicao
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> dist(mx, 0), extra(mx, 0);
    q.push({0, a, b});
    //aq eu calculo quantas distancias possiveis eu tenho e tbm quantos queijos ja tem nessa posicao
    while(!q.empty()){
        auto [d, x, y] = q.front(); q.pop();
        if(grid[x][y] == 'Q') extra[d]++;
        else if(grid[x][y] == '.') dist[d]++;
        for(int i = 0; i < 4; i++){
            int dx = x + d1[i];
            int dy = y + d2[i];
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= m) continue;
            if(grid[dx][dy] == '#' || visited[dx][dy]) continue;
            visited[dx][dy] = 1;
            q.push({d+1, dx, dy}); 
        }
    }

    int tot = 0, posicaomx = mx-1;
    for(int i = 1; i < mx; i++){
        tot += dist[i];
    }

    for(int i = 1; i < mx; i++){
        if(extra[i]){
            posicaomx = i;
            break;
        }
    }

    /*
    
    */

    /*
    de quantas maneiras eu consigo colocar k caras em posicoes maiores ou iguais a i?
    isso eh C(n-qtd[i-1]-1, k) se nao tiver nenhum ja na posicao i, e C(n-qtd[i-1], k) se tiver
    qtd total - qtd de ser pelo menos i 
    */
    int pr = 0, qtdtotal = 0, ans = 0;
    qtdtotal = comb(tot, k);
    for(int i = 1; i <= posicaomx; i++){
        //qtd total - qtd de ser pelo menos i
        ans = (ans + comb(tot-pr, k))%MOD;
        pr += dist[i];
    }

    cout << (ans*fastexpo(qtdtotal, MOD-2))%MOD << endl;
    
}

signed main(){
    //fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}