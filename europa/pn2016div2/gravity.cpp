#include <bits/stdc++.h>
using namespace std;


const int MAXN = 55;
int n, m;
char grid[MAXN][MAXN];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int j = 0; j < m; j++){
        int prev = n-1;
        for(int i = n-1; i>= 0; i--){
            if(grid[i][j] == '#'){
                prev = i-1;
            }
            if(grid[i][j] == 'o'){
                swap(grid[prev][j], grid[i][j]);
                prev--;
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