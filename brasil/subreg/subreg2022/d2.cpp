#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int cnt = 0;
    int npow =  1 << n;

    int x1 = 1 << (n - 1);
    int y1 = 1 << (n - 1);

    //(p+a)/2 , (q+b)/2 --> reverte para 2p - a , 2q - b
    //dobrar coordenadas(p,q) e tira a posição do atrator(a,b)
    while(x != x1 || y != y1){
        x = 2*x;
        y = 2*y;
        if(x >= npow/2) x -= npow;
        if(y >= npow/2) y -= npow;

        cnt++;
    }

    cout << cnt << endl;
    
}