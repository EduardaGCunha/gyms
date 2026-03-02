#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c; cin >> a >> b >> c;

    cout << min({(a*2+c*2), (a*4+b*2), (b*2+c*4)}) << endl;
}