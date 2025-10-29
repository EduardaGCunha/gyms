#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e3+7;
int pos[MAXN], mass[MAXN];

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> pos[i];
    for(int i = 0; i < n; i++) cin >> mass[i];

    cout << n-1 << endl;
    cout << fixed << setprecision(10);
    for(int i = 0; i < n-1; i++){
        //se o resultado for positivo, entao eu aumento o l, se for negativo eu diminuo o r
        //tem como o resultado ser negativo? 
        double l = pos[i], r = pos[i+1];
        for(int j = 0; j < 100; j++){
            double mid = l + (r-l)/2.0;
            double f1 = 0.0, f2 = 0.0;
            //aq eu pego todas as forças q forem menores q i, ou seja serao forças negativas
            for(int x = 0; x <= i; x++){
                double d = (mid-pos[x]);
                f1 += static_cast<double>(mass[x])/(d*d);
            }
            //aq todas as forças positivas
            for(int x = i+1; x < n; x++){
                double d = (mid - pos[x]);
                f2 += static_cast<double>(mass[x])/(d*d);
            }

            double res = f2 - f1;
            if(res < 0){
                l = mid;
            }else{
                r = mid;
            }
        }  
        cout << l << endl;
    }
}