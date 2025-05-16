#include <bits/stdc++.h>
using namespace std;

pair<string, int> arr[10];
int n;

int solve(int x){
    for(int i = 0; i < n; i++){
        if(arr[i].first == "ADD") x += arr[i].second;
        else if(arr[i].first == "MULTIPLY") x *= arr[i].second;
        else if(arr[i].first == "SUBTRACT"){
            x-=arr[i].second;
            if(x < 0) return 0;
        }else{
            if((x%arr[i].second) != 0) return 0;
            x/=arr[i].second;
        }
    }
    return 1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int cnt = 0;
    for(int i = 1; i <= 100; i++){
        if(!solve(i)) cnt++;
    }
    cout << cnt << endl;
}