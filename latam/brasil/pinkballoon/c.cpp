#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
o tamandua nao vai embora
se ele nao consegue comer inteiro, vc guarda o quanto ele ainda pode comer
ent se tiver algum tamandua que pode comer um ainda, vc escolhe q ele coma
*/
signed main(){
    int x, y, z, m, n;
    string s;
    cin >> x >> y >> z >> m >> n >> s;

    int a = 0;
    int r = 0;
    int f = 0;
    vector<int> t(1, m);
    auto nxt = [&](int idx, int goal) -> int{
        for(int i = idx; i < t.size(); i++){
            if(t[i] >= goal){
                return i;
            }
        }
        t.push_back(m);
        return t.size()-1;
    };

    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            if(t[a] < y) a = nxt(a, y);
            t[a] -= y;
        }else if(s[i] == 'F'){
            if(t[f] < x) f = nxt(f, x);
            t[f] -=x;
        }else{
            if(t[r] < z) r = nxt(r, z);
            t[r] -=z;
        }
    }

    cout << t.size() << endl;
}
