#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool check(int i, int j){
    while(i <= j){
        if(s[i] != s[j]) return false;
        i++, j--;
    }

    return true;
}

int main(){
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check(i, j)){
                ans = max(ans, (j-i+1));
            }
        }
    }

    cout << ans << endl;
}