#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int time1 = 0, time2 = 0;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        int x, y; cin >> x >> y;
        if(x == 1) time1 += y;
        else time2 += y;
    }
    cout << time1 << " x " << time2 << endl;
}