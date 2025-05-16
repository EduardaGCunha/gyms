#include <bits/stdc++.h>
using namespace std;


int main(){
    double t; cin >> t;
    int n; cin >> n;
    vector<double> val;
    val.push_back(0), val.push_back(t);
    for(int i = 0; i < n; i++){
        double a; cin >> a;
        val.push_back(a);
    }
    sort(val.begin(), val.end());

    double ans = 1e6+2;
    for(int i = 1; i <= n; i++){
        //cout << val[i] << endl;
        double cur, last;
        if(i-1 == 0) last = val[i];
        else last = (val[i] - val[i-1])/2.0;
        if(i == n) cur = (val[i+1] - val[i]);
        else cur = (val[i+1] - val[i])/2.0;
        ans = min(ans, last + cur);
    }

    cout << fixed << setprecision(2) << ans << endl;
}