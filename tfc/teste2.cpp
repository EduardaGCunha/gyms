#include <bits/stdc++.h>
using namespace std;

//contador de quantos acesos tem esse primo tal
int primos[MAXN];
void factorize(int x){
    for(int i = 2; i*i <= x; i++){
        if(!(x%i)){
            primos[x]++;
            while(!(x%i)) x/=i;
        }
    }
    if(x > 1) primos[x]++;
}

int main(){
    string s = "amos";
    sort(s.begin(), s.end());
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
}