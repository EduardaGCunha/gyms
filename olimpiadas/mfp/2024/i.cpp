#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long


signed main(){
    fastio;
   int n; cin >> n;
   cin.ignore();
   vector<vector<string>> val;
   for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int k = 0, j = 0;
        vector<string> v;
        while(j < s.size()){
            if(s[j] == ' '){
                string t;
                for(int x = k; x < j; x++){
                    t+=s[x];
                }
                v.push_back(t);
                k = j+1;
            }
            j++;
        } 
        string t;
        for(int x = k; x < j; x++){
            t+=s[x];
        }
        v.push_back(t);
        val.push_back(v);  
    }

    int m; cin >> m;
    int result[n];
    int ans = 0;
    map<string, int> points;
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        int p; cin >> p;
        points[s] = p;
    }
    for(int i = 0; i < n; i++){
        int x = 0;
        for(auto u : val[i]){
            if(points.count(u)){
                x += points[u];
            }
        }
        result[i] = x;
        ans += x;
    }
    cout << ans << " ";
    int mm = 0, idx = -1;
    for(int i = 0; i < n; i++){
        if(mm <= result[i]){
            mm = result[i];
            idx = i;
        }
    }
    cout << idx+1 << endl;

}