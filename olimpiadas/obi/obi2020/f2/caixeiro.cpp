#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1e5;
vector<pair<int, int>> graph[MAXN];
int visited[MAXN];

int main(){
    cin >> n;
    int t= n*(n-1)/2;
    for(int i = 0; i < t; i++){
        int a, b, c; cin >> a >> b;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    //for(int i = 0; i <)
}