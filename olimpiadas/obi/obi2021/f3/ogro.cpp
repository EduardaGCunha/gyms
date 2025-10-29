#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    if(n > 0){
        for(int i = 0; i < min(n, 5); i++) cout << "I";
    }else cout << "*";
    cout << endl;
    if(n > 5){
        for(int i = 0; i < min(n-5, 5); i++) cout << "I";
    }else cout << "*";
    cout << endl;
}