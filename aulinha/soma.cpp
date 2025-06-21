#include <bits/stdc++.h>
using namespace std;

/*
1. banana
2. maca
3. tempero
4. laranja 
5. tamarindo 
6. manga
*/

const int MAXN = 7;
int arr[MAXN];

int main(){
    int n; cin >> n;
    string gabarito, candidato; cin >> gabarito >> candidato;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(gabarito[i] == candidato[i]) ans++;
    }
    cout << ans << endl;

}