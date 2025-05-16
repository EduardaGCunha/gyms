#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int x = abs((a+b) - (c+d));
    int y = abs((a+c) - (b+d));
    int z = abs((a+d) - (b+c));

    cout << min({x, y, z}) << endl;

}