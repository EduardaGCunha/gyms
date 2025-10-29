#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

int n, c; 
bool compat(string t, string s) {
    for (int i = 0; i < c; i++) {
        if (s[i] != '*' && s[i] != t[i])
            return false;
    }
    return true;
}

signed main(){
    fastio;
    cin >> n >> c;
    vector<string> strs(n);
    vector<int> buraco(n);
    vector<vector<int>> v(c, vector<int>(26, 0));

    for (int i = 0; i < n; i++){
        cin >> strs[i];
        for (int j = 0; j < c; j++){
            if (strs[i][j] != '*'){
                v[j][strs[i][j] - 'a']++;
            }else buraco[i] = j;
        }
    }

    int ans = -1;
    string bestres(c, '*');
    for (int i = 0; i < n; i++){
        int p = buraco[i];
        string t(c, '*');

        for (int j = 0; j < c; j++){
            if (j != p) t[j] = strs[i][j];
        }

        //cout << t << endl;
        for (char j = 'a'; j <= 'z'; j++){
            t[p] = j;

            int cnt = 0;
            for (int k = 0; k < n; k++){
                if (compat(t, strs[k]))
                    cnt++;
            }
            //cout << cnt << " " << bestres << " " << t << endl;
            if (cnt > ans || (cnt == ans && t < bestres)){
                ans = cnt;
                bestres = t;
            }
        }
    }

    cout << bestres << " " << ans << "\n";
    return 0;
}
