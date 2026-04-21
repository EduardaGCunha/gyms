#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

/*
coloco tudo num multiset com 0 simbolizando q ta descendo e 1 q ta subindo
primeiro eu checo se for igual a d
    se for igual a d mas ja foi encontrado outro, ent continue
    se nn guardo esse idx
p/ cada numero desse vetor, eu diminuo em 1 se tiver com 0 ou aumento em 1 se tiver com 1

se encontrei algum possivel, removo do multiset

*/

void solve(){
    int n, d; cin >> n >> d;
    priority_queue<pair<int, int>> pq, pq2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push({1, x});
    }

}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
}