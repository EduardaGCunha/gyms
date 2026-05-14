#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
a moral dessa questao eh o seguinte:
estou na posicao N/2, N/2
testo mover em 1 das 4 direcoes
se foi possivel em 1 delas (o return foi -), entao eu continuo somente com essa 
quando eu chegar em uma posicao tal q se eu tentar andar nas outras direcoes possiveis e o resultado for + em todas, ent eu printo !
*/

map<int, char> mp = {
    {0, 'D'},
    {1, 'R'},
    {2, 'U'},
    {3, 'L'}
};

int n;
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

tuple<bool, int, int> consulta(int op, int x, int y){
    int dx = x + d1[op];
    int dy = y + d2[op];
    if(dx < 0 || dx >= n) return {false, x, y};
    if(dy < 0 || dy >= n) return {false, x, y};
    cout << "? " << mp[op] << endl;
    char k; cin >> k;
    return {(k == '-'), dx, dy};
}

void move(int op){
    cout << "M " << mp[op] << endl;
}

void solve(){
    cin >> n;
    int a = n/2, b = n/2;
    //dir, x, y;
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < 4; i++){
        auto [res, dx, dy] = consulta(i,a, b);
        if(res){
            q.push({i, dx, dy});
            move(i);
            break;
        }
    }

    while(!q.empty()){
        auto [dir, x, y] = q.front(); q.pop();
        auto [res, dx, dy] = consulta(dir,x, y);
        if(res){
            q.push({dir, dx, dy});
            move(dir);
            continue;
        }

        int pos = 0;
        for(int i = 0; i < 4; i++){
            if(i == dir) continue;
            auto [res1, dx1, dy1] = consulta(i,x, y);
            if(res1){
                pos = 1;
                q.push({i, dx1, dy1});
                move(i);
                break;
            }
        }

        if(!pos){
            cout << "!\n";
            break;
        }
    }

    
}

signed main() {
    //fastio;
    solve();
    return 0;
}