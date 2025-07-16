#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n;
    cin >> n;
    int mat[50][50];
    for(int i=0  ;i<n ; i++){
        for(int j=0 ;j<n ; j++){
            cin >> mat[i][j];
        }
    }

    // CANTO [0][0]
    bool ok = true;
    for(int i=0 ; i<n-1 ;i++){
        if(mat[0][i]>=mat[0][i+1]){
            ok = false;
            break;
        }
        if(mat[i][0]>=mat[i+1][0]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << 0 << endl;
        return 0;
    }

    ok = true;
    for(int i=0 ; i<n-1 ;i++){
        if(mat[i][n-1]>=mat[i+1][n-1]){
            ok = false;
            break;
        }
        
    }
    for(int i=n-1 ; i>0 ; i--){
        if(mat[0][i]>=mat[0][i-1]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << 1 << endl;
        return 0;
    }

    ok = true;
    for(int i=n-1 ; i>0 ; i--){
        if(mat[i][n-1]>=mat[i-1][n-1]){
            ok = false;
            break;
        }
    }
    for(int i=n-1 ; i>0 ; i--){
        if(mat[n-1][i]>=mat[n-1][i-1]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
    return 0;

}