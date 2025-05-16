#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    int arr1[n], arr2[n];
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];

    double win = 0, tie =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr1[i] > arr2[j]) win++;
            if(arr1[i] == arr2[j]) tie++;
        }
    }

    float ans = win/(36 - tie);
    cout << fixed << setprecision(5) << ans << endl;
}