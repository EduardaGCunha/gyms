#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int MAXN = (1e5)+7;
int bit[2][MAXN];
int freqx[MAXN], freqy[MAXN];

void upd(int x, int tp, int delta){
    for(; x <= MAXN; x += (x&-x)) bit[tp][x] += delta;
}

int sum(int x, int tp){
    int ans = 0;
    for(; x; x-= (x&-x)) ans += bit[tp][x];
    return ans;
}

signed main(){
    int n, m, q; cin >> n >> m >> q;
    while(q--){
        char a; cin >> a;
        if(a == 'A'){
            int l, r; cin >> l >> r;
            if(!freqx[l]) upd(l, 0, 1);
            if(!freqy[r]) upd(r, 1, 1);
            freqx[l]++, freqy[r]++;
            //cout << "entrou aqui no A\n";
        }else if(a == 'R'){
            int l, r; cin >> l >> r;
            freqx[l]--, freqy[r]--;
            if(!freqx[l]) upd(l, 0, -1);
            if(!freqy[r]) upd(r, 1, -1);
            //cout << "entrou aqui no R\n";
        }else{
            //cout << "entrou aqui no Q\n";
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            int totalx = (x2-x1+1) - (sum(x2, 0) - sum(x1-1, 0)); 
            int totaly = (y2-y1+1) - (sum(y2, 1) - sum(y1-1, 1)); 
            //cout << totalx << " " << totaly << endl;
            if(totalx > 0 && totaly > 0) cout << 'N' << endl;
            else cout << 'S' << endl;
        }
    }
}