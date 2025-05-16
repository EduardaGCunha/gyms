#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;
char grid[MAXN][MAXN];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int j = 0; j < m; j++){
        int lst = n-1;
        for(int i = n-1; i >= 0; i--){
            if(grid[i][j] == '#') lst = i-1;
            if(grid[i][j] == 'o'){
                swap(grid[lst][j], grid[i][j]);
                lst--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    
}