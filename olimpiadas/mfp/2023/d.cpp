#include <bits/stdc++.h>
using namespace std;

int main(){
    double m1, m2, x1, x2, f; 
    cin >> m1 >> m2 >> x1 >> x2 >> f;
    
    double num = f*((x1 - x2)*(x1 - x2));
    double base = m1*m2; 
    double res = num/base;
    cout << setprecision(10) << fixed << res << endl;
}