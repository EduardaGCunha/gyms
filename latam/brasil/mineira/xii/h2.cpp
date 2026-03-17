#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

/*
o que eu preciso guardar?
priority_queue 
v1, posicao inicial, momento q foi removido
*/



void solve(){
    int n; cin >> n;
    vector<multiset<int>> elim(n+2);
    int x; cin >> x;
    if(x != 0){
        cout << -1 << endl;
        return;
    }

    elim[n+1].insert(1);
    int m = (1<<n);
    int arr[m];
    arr[1] = 0;
    n++;
    vector<int> res((m+1)*5+7, 0);
    for(int i = 2; i <= m; i++){
        cin >> x;
        arr[i] = x;
        elim[x].insert(i);
    }

    
    multiset<int> positions;
    for(int i = 1; i <= m; i++) positions.insert(i);

    int rodada = 1;
    while(!positions.empty()){
        vector<int> pos;
        bool toggle = true;
        for(auto u : positions){
            if(toggle) pos.push_back(u);
            toggle = !toggle;
        }

        for(auto k : pos){
            int v = *(elim[rodada].begin());
            res[k] = v;
            elim[rodada].erase(elim[rodada].begin());
            positions.erase(k);
        }
        rodada++;
    }

    vector<vector<int>> turnos(n+1);
    for(int i = 1; i <= m; i++){
        turnos[1].push_back(res[i]);
    }


    for(int i = 1; i <= m; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    int cnt = 1;
    while(cnt != n){
        for(int i = 0; i < turnos[cnt].size(); i+=2){
            int a = turnos[cnt][i];
            int b = turnos[cnt][i+1];
            //cout << a << " " << b << " " << arr[a] << " " << arr[b] << endl;
            if(a > b) swap(a, b);
            turnos[cnt+1].push_back(a);
            if(arr[b] != cnt){
                cout << -1 << endl;
                return;
            }
        }
        cnt++;
    }

    for(int i = 1; i <= m; i++){
        cout << res[i] << " ";
    }
    cout << endl;
}

signed main(){
    //fastio;
    //int t; cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
}