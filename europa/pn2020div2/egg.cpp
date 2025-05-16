#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int low = k, high = 1;
    for(int i = 0; i < n; i++){
        int a; string b;
        cin >> a >> b;
        if(b == "BROKEN") low = min(low, a);
        else high = max(high, a);
    }

    cout << high+1 << " " << low-1<< endl;
}