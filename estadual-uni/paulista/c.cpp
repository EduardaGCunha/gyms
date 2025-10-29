#include <bits/stdc++.h>
using namespace std;

bool is_in(int x, int a, int b){
    return a<=x && x<=b;
}

bool check_sum(int x, int y, int val){
    return abs(x) + abs(y) <= val;
}

int main(){
    int n, x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        bool pos = false;
        if(is_in(x, -100, 0) && is_in(y, 0 , 100)){
            pos = true;
        }
        else if(is_in(x, 0, 100) && is_in(y, -100, 0)){
            pos = true;
        }
        else if(is_in(x, -200, -100) && is_in(y, 0, 100) && check_sum(x, y, 200)){
            pos = true;
        }
        else if(is_in(x, 0, 100) && is_in(y, 0, 100) && check_sum(x, y, 100)){
            pos = true;
        }
        else if(is_in(x, -100, 0) && is_in(y, -100, 0) && check_sum(x, y, 100)){
            pos=true;
        }
        else if(is_in(x, 100, 200) && is_in(y, -100, 0) && check_sum(x, y, 200)){
            pos=true;
        }
        if(pos) cout << "S" << endl;
        else cout << "N" << endl;
    }
} 