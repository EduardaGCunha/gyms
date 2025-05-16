#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main(){
    fastio;
    int n = 6;
    int arr[n], brr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];

    double cnt = 0, igual = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] > brr[j]) cnt++;
            if(arr[i] == brr[j]) igual++;
        }
    }

    double ans = cnt/(36 - igual);
    cout << fixed << setprecision(5) << ans << endl;
}