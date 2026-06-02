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
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n-1; i++) cout << s[i];
    if(s[n-1] == 'u') cout << "ivis\n";
    else cout << s[n-1] << endl;
}
