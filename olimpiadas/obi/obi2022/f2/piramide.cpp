#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 100;
int arr[MAXN][MAXN];

void func(int x, int f, int c){
    if(c > (n+1)/2) return;

    for(int i = x; i < f; i++){
        arr[i][x] = c;
        arr[x][i] = c;
    }

    for(int i = f; i >= x; i--){
        arr[i][f] = c;
        arr[f][i] = c;
    }

    func(x+1, f-1, c+1);
}

int main(){
    cin >> n;
    func(0, n-1, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}