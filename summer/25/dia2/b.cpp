#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 1e3+7;
vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    map<char, int> mp;
    for(int i = 0; i < 26; i++){
        char a = 'A' + i;
        mp[a] = i;
    }
    
    while(t--){
        char a; 
        cin >> a;
    
        string s; 
        getline(cin, s);
        int n = mp[a];
        for(int i = 0; i <= n; i++){
            graph[i].clear();
            visited[i] = 0;
        }
        
        while(getline(cin, s) && !s.empty()){
            int a = mp[s[0]];
            int b = mp[s[1]];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int c = 0;
        for(int i = 0; i <= n; i++){
            if(!visited[i]){
                dfs(i);
                c++;
            }
        }
        cout << c << endl;
        if(t > 0) cout << endl;
    }
}