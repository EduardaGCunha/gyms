#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define int long long
#define MAXN 1e9

vector<int> primos;
void factorize(int y){
  int copia = y;
  primos.push_back(1);
  //cout << 1 << endl;
  for(int i=2 ; i*i<=y ; i++){
    if(!(y%i)){
      //cout << i << endl;
      
      while(!(y%i)){ 
        primos.push_back(i*primos.back());
        y/=i;
      };
    }
  }
  primos.push_back(copia);
}

int somaPA(int a1, int an, int n){
  return ((a1+an)*n)/2;
}

int result1(int y, int k){
  //cout << endl << endl;
  int total = 0;
  int i;
  for(i=0 ; i<primos.size()-1 ; i++){
    //cout << primos[i] << " ";
    int an = primos[i+1]-primos[i];
    int n = an/primos[i];
    if(n>k){
      return k+primos[i];
    }
    //cout << "primo:" << primos[i] << " A1:" << primos[i] << " An:" << primos[i+1] << "-" << primos[i] << "=" << an << " N:" << n << " somaPA:" <<  somaPA(primos[i], an, n) << " total:" << somaPA(primos[i], an, n) + n*primos[i] << endl;
    //total += somaPA(primos[i], an, n) + n*primos[i];
    k -= an/primos[i];
  }
  //cout <<  " An:" << k*y << " total:" << k*y + y << endl;
  //cout << primos[i] << endl;
  return k*y + y;
}

int result2(int y, int k){
  int x = 1;
  int i = k;
  while(k--){
    if(i-k<10 || k<10 || x==y ||  x + __gcd(x, y)==y) cout << i - k << ": " << x << " + " << __gcd(x, y) << endl;
    x = x + __gcd(x, y);
  }
  return x;
}

signed main()
{
  int y, k, x=1;

  cin >> y >> k;
  int i=k;
  factorize(y);

  //cout << result1(y, k) << endl; 

  srand (time(NULL));
  int q = 1000;
  while(q--){
    int y = rand() % 1000000000 + 1;
    int k = rand() % 1000000000 + 1;
    factorize(y);
    int a = result1(y, k);
    int b = result2(y, k);
    if(a!=b){
      cout << y << " " << k << endl;
      cout << a << " " << b << endl;
      cout << endl;
    }
  }

 

  return 0;
}