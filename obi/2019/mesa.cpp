#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    int posa = (a%3);
    int posb = (b%3);
    vector<int> visited(3, 0);
    if(posa == posb){
        posb = (posb+1)%3;
    }

    visited[posa] = 1;
    visited[posb] = 1;
    for(int i = 0; i < 3; i++){
        if(!visited[i]){
            cout << i << endl;
            break;
        }
    }

}