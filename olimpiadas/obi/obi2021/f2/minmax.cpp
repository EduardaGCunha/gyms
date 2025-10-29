#include <bits/stdc++.h>
using namespace std;

int s, a, b;

bool check(int val){
    int sum = 0;
    while(val > 0){
        sum += val%10;
        val /= 10;
    }
    return sum == s;
}

int main(){
    cin >> s >> a >> b;

    int mini = INT_MAX, maxi = 0;
    for(int i = a; i <= b; i++){
        if(check(i)){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
    }

    cout << mini << endl << maxi << endl;
}