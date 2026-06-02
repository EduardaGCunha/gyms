#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main(){
    fastio;
    int n, m;
    while(cin >> n >> m){
        int a = n-1, b= m-1;
        int g = gcd(a, b);
        int intersect = ((a/g - 1) * (b/g -1))/2;

        int visited = lcm(a, b) +1 - intersect;
        cout << (n*m) - visited << endl;
    }
}
