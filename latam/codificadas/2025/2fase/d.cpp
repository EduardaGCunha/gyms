#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
entre todos os vertices q estiverem entre os dois q tem mais filhos, precisarei fazer essa quantidade
q nao seja folha
todo mundo q estiver ha uma distancia maior q 1 a partir do 
*/

const int MAXN = 1e5+7;
vector<int> graph[MAXN];
int visited[MAXN];

signed main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
    }
    
    
}