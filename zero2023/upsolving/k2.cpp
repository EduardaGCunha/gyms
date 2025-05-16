#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        vector<set<int>> v(4);
        for(int i = 0; i <= 216; i++){
            int a = i*i*i*i*1LL;
            if(a > n) break; 
            for(int j = i; j <= 216; j++){
                int b = j*j*j*j*1LL;
                if(b > n) break; 
                for(int k = j; k <= 216; k++){
                    int c = k*k*k*k*1LL;
                    if(c > n) break; 
                    int d = n - (a + b + c);
                    if (d >= 0) {
                        double rd = sqrt(sqrt((double)d)); 
                        long long dd = llround(rd);            
                        if (dd*dd*dd*dd == d){
                            a = i, b = j, c = k, d = dd;
                            if(a > d) swap(a, d);
                            else if(b > d) swap(b, d);
                            else if(c > d) swap(c, d);
                            v[0].insert(a);
                            v[1].insert(b);
                            v[2].insert(c);
                            v[3].insert(dd);
                        }
                    }
                }
            }
        }

        
        cout << v[0].size() << endl;
        vector<vector<int>> ans;
        for(int i = 0; i < v[0].size(); i++){
            for(auto u : v[i]){
                ans[i].push_back(u);
            }
        }

        for(int i = 0; i < v[0].size(); i++){
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
        }
    }
}