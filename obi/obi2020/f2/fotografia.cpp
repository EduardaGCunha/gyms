#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, l; cin >> a >> l;
    int area = a*l;
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        arr[i] = a*b;
    }

    int res = -2;
    int prev = INT_MAX;
    for(int i = 0; i < n; i++){
        //cout << arr[i] << endl;
        if(area <= arr[i] && arr[i] - area < prev){
            prev = arr[i] - area;
            res = i;
        }
    }

    cout << res+1 << endl;
}