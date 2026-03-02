#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 2*(1e5)+7;

int n, m, s, total;

int calc_area(int x, int y, int r){
    int a =1 ;
    int alt = min(n, r+y) -max(y-r, a) + 1;
    int larg =  min(m, r+x) - max(x-r, a) + 1;
    //cout << alt << " " << larg << endl;
    return alt*larg;
}

signed main(){
    cin >> n ;
    while(n>=10){
        cout << n << endl;
        n = (n%10) + ((n/10)*3);
    }
    cout << n << endl;
}
