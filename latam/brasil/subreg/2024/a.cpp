#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
int n, k;
cin >> n >> k;
if(n == 1){
    cout << k << endl;
} 
else{cout << (k- n + 1)/n << endl;}
}