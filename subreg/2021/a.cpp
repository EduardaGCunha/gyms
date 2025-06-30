#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int soma = 0;
    for(int i = 0; i < n; i++){
        cin >> i;
        soma += i;
        cout << soma << endl;
    }
}