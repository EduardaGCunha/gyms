#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long


signed main(){
    int n; cin >> n;
    string s; cin >> s;
    int cost = 0, sum = 0;
    for(int i = 0; i < s.size(); i+=n){
        for(int j = i; j < i + n; j++){
            if(s[j] == '1') sum += 2;
        }
        sum += cost;
        cost++;
    }
    cout << sum << endl;
}