#include <bits/stdc++.h>
using namespace std;

int n,s;
vector<vector<int>> adj;
vector<int> mask;

void dfs(int x, int ant){


    for(int i=0; i<adj[x].size(); i++){

        int viz = adj[x][i];
        if(viz == ant) continue;

        mask[viz] = mask[viz] | mask[x];

        dfs(viz, x);
    }
    return;
}

int acesos(int x){

    int cont = 0;

    for(int i=0; i<= 20; i++){

        int bit = 1 << i;

        if((bit & x) != 0) cont++;
    }
    return cont;
}

int main(){

    cin >> n >> s;

    adj.resize(n+1);
    mask.resize(n+1);

    for(int i=1; i<=n; i++){

        int k; cin >> k;
        int fig = 0; // conjunto representando as figurinhas;

        for(int j=0; j<k; j++){

            int f; cin >> f;

            int bit = 1 << f;
            fig |= bit;
        }

        mask[i] = fig;
    }


    for(int i=0; i<n-1; i++){

        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(s,0);

    int q; cin >> q;

    for(int i=0; i<q; i++){

        int d; cin >> d;
        cout << __popcount(mask[d]) << endl;
    }

    return 0;
}