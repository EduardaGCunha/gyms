#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5*(1e5);
map<int, int> mp;
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    if(v-1 >= 1 && mp[v-1] > mp[v]){
        dfs(v-1);
    }
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!visited[arr[i]]){
            ans++;
            dfs(arr[i]);
        }
    }

    cout << ans << endl;
}