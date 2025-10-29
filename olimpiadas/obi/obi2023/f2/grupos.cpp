#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
pair<int, int> quer[MAXN], naoquer[MAXN];

int main(){
    int e, m, d;
    cin >> e >> m >> d;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        quer[i] = {a, b};
    }

    for(int i = 0; i < d; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        naoquer[i] = {a, b};
    }

    int cnt = 0;
    vector<int> mp (MAXN);
    for(int i = 0; i < e/3; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--, c--;
        mp[a] = cnt;
        mp[b] = cnt;
        mp[c] = cnt;
        cnt++;
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        if(mp[quer[i].first] != mp[quer[i].second])ans++;
        
    }

    for(int i = 0; i < d; i++){
        if(mp[naoquer[i].first] == mp[naoquer[i].second]) ans++;
    }

    cout << ans << endl;


}