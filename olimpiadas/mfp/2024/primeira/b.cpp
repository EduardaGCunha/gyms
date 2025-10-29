#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, vector<int>> mpx;
    map<int, vector<int>> mpy;
    for(int i = 0; i < 4; i++){
        int x, y; cin >> x >> y;
        mpx[x].push_back(y);
        mpy[y].push_back(x);
    }

    int sidea = 0, sideb=0;
    for(auto u : mpx){
        if(u.second.size() == 1) continue;
        sidea = abs(u.second[0] - u.second[1]);
    }

    for(auto u : mpy){
        if(u.second.size() == 1) continue;
        sideb = abs(u.second[0] - u.second[1]);
    }

    cout << sidea * sideb << endl;
    
}