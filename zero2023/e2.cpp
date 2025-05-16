#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e4+7;
int arr[MAXN], brr[MAXN];

signed main(){
    fastio;
    int n; cin >> n;
    set<int> arr; 
    set<int> brr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        brr.insert(x);
    }

    map<int, int> mp;

    for(auto u : brr){
        mp[abs(*arr.begin() - u)]++;
        mp[*arr.begin() + u]++;
    }

    for(auto u : arr){
        for(auto v : brr){
            int x = abs(u - v);
            int y = u + v;
            if(mp.find(x) != mp.end()){
                mp[x]++;
            }
            if(mp.find(y) != mp.end()){
                mp[y]++;
            }
        }
    }

    for(auto u : mp){
        cout << u.first << " " << u.second << endl;
        if(u.second == n){
            cout << u.first << endl;
        }
    }
}