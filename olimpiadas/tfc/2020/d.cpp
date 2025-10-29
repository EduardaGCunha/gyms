#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back(a%b);
    }

    sort(v.begin(), v.end());
    cout << v[k-1] << endl;
}