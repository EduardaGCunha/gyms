#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    vector<string> palavras;
    int n, m;
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        string aux; cin >> aux;
        palavras.push_back(aux);
    }
    for(int i=0 ; i<m ; i++){
        vector<int> letra(26, 0);
        int maior_idx = 0;
        for(int j=0 ; j<n ; j++){
            int pos = (palavras[j][i] - 'a');
            //cout << "pos:" << pos << endl;
            letra[pos]++;
            if(letra[pos]>letra[maior_idx]){
                maior_idx = pos;
            }
            else if(letra[pos]==letra[maior_idx] && pos < maior_idx){
                maior_idx = pos;
            }
        }
        char c = 'a' + maior_idx;
        cout << c;
    }
    cout << endl;
}