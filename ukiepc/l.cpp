#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    string arm = "\U0001F4AA";
    string leg = "\U0001F9B5";
    string rest = "\U0001F60E";
    int n; cin >> n;
    vector<string> ans;
    for(int i = 0; i < n; i++){
        string treino; cin >> treino;
        if(treino.find("rest") != treino.npos){
            ans.push_back(rest);
        }else if(treino.find("leg") != treino.npos){
            ans.push_back(leg);
        }else{
            ans.push_back(arm);
        }
    }

    int sz = ans.size();
    int cnt = 0;
    for(int j = 1; j <= 5; j++){
        cout << j << " ";
        for(int i = 0; i < 7; i++){
            if(j == 5 && i > 2){
                break;
            }
            cnt = cnt%sz;
            cout << ans[cnt];
            cnt++;
        }
        cout << endl;
    }
}