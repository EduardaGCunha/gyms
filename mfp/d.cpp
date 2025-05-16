#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const int MAXN = 6;
int grid[MAXN][MAXN];
int ans = 0;

void pd(int i, vector<int> visited, int sum){
    //cout << i << " " << sum << endl;
    if(i == MAXN){
        ans = max(ans, sum);
    }
    int ans = sum;
    for(int j = 0; j < MAXN; j++){
        if(!visited[j]){
            visited[j] = 1;
            pd(i+1, visited, sum + grid[i][j]);
            visited[j] = 0;
        }
    }
}

signed main(){
    fastio;
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            cin >> grid[i][j];
        }
    }
    vector<int> visited(MAXN, 0);
    pd(0, visited, 0);
    cout << ans << endl;
}