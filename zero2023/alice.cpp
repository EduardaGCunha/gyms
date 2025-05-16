#include <bits/stdc++.h>
using namespace std;

int main(){
    char game[3];
    int contx = 0;
    for(int i = 0; i < 3; i++){
        cin >> game[i];
        if(game[i] == 'X'){
            contx++;
        }
    }

    if(contx != 2){
        cout << "?" << endl;
        return 0;
    }

    if((game[0] == 'X' && game[1] == 'X') || (game[1] == 'X' && game[2] == 'X')){
        cout << "Alice" << endl;
    }
    else{
        cout << "*" << endl;
    }
}