#include <bits/stdc++.h>
using namespace std;

int main(){
    double c, d, t; cin >> c >> d >> t;
    
    if(d - t*c < 0){
        cout << "0.0" << endl;
        return 0;
    }
    cout << fixed << setprecision(1) << (d - t*c)/c << endl; 
}