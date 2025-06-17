#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int n; cin >> n;
    vector<set<int>> graph(26);
    vector<int> indeg(26, 0);
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 1; j < s.size(); j++){
            int a = s[j-1] - 'a';
            int b = s[j] - 'a';
            if(a == b) continue;
            
            if(graph[a].find(b) == graph[a].end()){
                graph[a].insert(b);
                indeg[b]++;
            }
        }
    }
    
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(indeg[i] == 0) q.push(i);
    }
    
    vector<int> toposort;
    while(!q.empty()){
        int v = q.front(); q.pop();
        toposort.push_back(v);
        
        for(auto u : graph[v]){
            indeg[u]--;
            if(indeg[u] == 0) q.push(u);
        }
    }
    
    if(toposort.size() != 26){
        cout << "NAO" << endl;
        return 0;
    }
    
    
    cout << "SIM" << endl;
    for(int i = 0; i < 26; i++){
        cout << (char)(toposort[i] + 'a');
    }
    cout << endl;
}