#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)


//se esse bit tiver ligado, ent eu do
//um flip no t
//c1 e c2 ativo ent inverte t

int main(){
    fastio;
    int n, m; cin >> n >> m;
    n = (1<<n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) arr[i] = i;

    for(int i = 0; i < m; i++){
        int op; cin >> op;
        op--;
        if(!op){
            int c, t; cin >> c >> t;
            for(int j = 0; j < n; j++){
                if(arr[j] & (1 << c)) arr[j] ^= (1<<t);
                //cout << arr[i] << " ";
            }
            //cout << endl;
        }else{
            int c1, c2, t; cin >> c1 >> c2 >> t;
            for(int j = 0; j < n; j++){
                //inverte
                if((arr[j]&(1<<c1)) && (arr[j]&(1<<c2))) 
                    arr[j] ^= (1<<t);
                
            }
        }
    }

    string s(n, '0');
    for(int i = 0; i < n; i++){
        fill(s.begin(), s.end(), '0');
        s[arr[i]] = '1';
        cout << s << endl;
    }
}