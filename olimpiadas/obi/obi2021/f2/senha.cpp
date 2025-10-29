#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007

int fast_expo(int b, int p){
    int res = 1;
    while(p > 0){
        if(p&1){
            res = (res*b)%MOD;
        }
        b = (b*b)%MOD;
        p = p/2;
    }
    return res;
}

signed main(){
    int n, m, k, p; cin >> n >> m >> k;

    string s; cin >> s;
    vector<int> pos;
    for(int i = 0; i < n; i++){
        if(s[i] == '#') pos.push_back(i);
    }

    string arr[m];
    for(int i = 0; i < m; i++){
        string a; cin >> a;
        sort(a.begin(), a.end());
        arr[i] = a;
    }

    cin >> p;
    int o = p;

    int val = fast_expo(k, m);
    int idx = 0;
    string s1 = s;
    while(idx < m){
        if(idx == m-1){
            s1[pos[idx]] = arr[idx][p];
            break;
        }
        val /= k;
        s1[pos[idx]] = arr[idx][p/val];
        p %= val;
        idx++;
    }
    cout << s1 << endl;

    //current string && string index
    // queue<pair<string, int >> q; 
    // q.push({s, 0});

    // vector<string> ans;
    // int cnt = 0;
    // while(!q.empty()){
    //     auto [st, idx] = q.front(); q.pop();
    //     //cout << idx << endl;
    //     if(idx == pos.size()){
    //         cnt++;
    //        // cout << "entro aq " << st << endl; 
    //         ans.push_back(st);
    //         continue;
    //     }
    //     for(int i = 0; i < k; i++){
    //         st[pos[idx]] = arr[idx][i];
    //         cout << st << endl;
    //         q.push({st, idx+1});
    //     }
    // }

    // sort(ans.begin(), ans.end());
    // cout << cnt << endl;
    // cout << ans[p-1] << endl;
}