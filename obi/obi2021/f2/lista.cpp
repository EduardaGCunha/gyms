#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int i = 0, j = n-1, se = arr[i], sd = arr[j];
    int cnt = 0;
    while(i < j){
        if(sd == se){
            i++;
            j--;
            sd = arr[j];
            se = arr[i];
        }else if(se < sd){
            i++;
            se += arr[i];
            cnt++;
            if(i == j) break;
        }else{
            cnt++;
            j--;
            sd += arr[j];
            if(i == j) break;
        }
    }

    cout << cnt << endl;
}