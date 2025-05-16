#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int arr[m];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        int c = 1 << a;
        c |= 1 << b;
        arr[i] = c;
    }

    int cnt = (1<<n)-1;
    for(int i = 1; i < (1<<n); i++){
        for(auto a : arr){
            if((i & a) == a){
                cnt--;
                break;
            }
        }
    }

    cout << cnt << endl;
}