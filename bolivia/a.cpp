#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'
#define dbg(x) cout << x << " ";


int func(int a, int b, int c, int x){
    return 2*a*x*x*x + 3*b*x*x + 6*c*x;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b, c, l, r; cin >> a >> b >> c >> l >> r;
        int delta = b*b - 4*a*c;
        vector<int> v;
        v.push_back(l);
        v.push_back(r);
        if(delta >= 0){
            delta = round(sqrt(delta));
            int x1 = (-b + delta)/2*a;
            int x2 = (-b - delta)/2*a;

            if(x1 > l && x1 < r){
                v.push_back(x1);
            }
            if(x2 > l && x2 < r){
                v.push_back(x2);
            }
        }

        sort(v.begin(), v.end());
        int tot = 0;
        for(int i = 0; i < v.size()-1; i++){
            int x1 = v[i];
            int x2 = v[i+1];
            tot += abs(func(a, b, c, x1) - func(a, b, c, x2));
        }

        int d = gcd(tot, 6);
        cout << tot/d << "/" << 6/d << endl;
    }
}
