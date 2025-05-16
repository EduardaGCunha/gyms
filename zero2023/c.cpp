#include <bits/stdc++.h>
using namespace std;

int main(){
    char question;
    long double a, b, c, total;
    cin >> a >> b >> c;
    cin >> question;

    if(question == 'A'){
        total = a + 1.5*b + 2.5*c;
    }

    else if(question == 'B'){
        long double newA = a + 2.5*c;
        total = b + newA / 1.5;
    }

    else if(question == 'C'){
        long double newA = a + b*1.5;
        total = c + newA / 2.5;
    }

    long long int totalfinal = total;

    cout << totalfinal << endl;
}