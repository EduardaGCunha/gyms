#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[8];
    int pos = 1;
    for(int i  =0; i < 8; i++){
        cin >> arr[i];
        if(arr[i] == 0 || arr[i] == 1) continue;
        pos = 0;
    }
    if(!pos) cout << "F" << endl;
    else cout << "S" << endl;
}