#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d; cin >> a >> c >> b >> c >> d >> c >> c >> c;
    if (a!=b) cout << pow((max(a,b)-min(a,b)),2) << endl;
    else{
        cout << pow((max(a,d)-min(a,d)),2) << endl;
    }

}