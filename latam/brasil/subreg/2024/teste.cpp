#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int to_int(string n){
    int pot = 1;
    int total = 0;
    for(int i=n.size()-1 ; i>=0 ; i--){
        if(n[i]=='1') total += pot;
        pot *= 2;
    }
    return total;
}

string to_bit(int n){
    string total = "";

    while(n>0){
        total += '0' + n%2;
        n = n/2;
    }
    reverse(total.begin(), total.end());
    return total;
}

int resto(string m, string n){
    int val_n = to_int(n);
    int del = max((int)61, (int)n.size()+1);
    while(m.size() > del){
        int val_m = to_int(m.substr(0, del));
        m = to_bit(val_m%val_n) + m.substr(del);
    }
        
    return to_int(m)%val_n;


}


signed main() {
    fastio;
    cout << LLONG_MAX << endl;
    cout <<"alo" << endl;
    for(int i=2 ; i<=100 ; i++){
        for(int j=2 ; j<=100 ; j++){
            //cout << i*1000 + j << " ";
            if(j%i != resto(to_bit(j), to_bit(i))) cout << j << "%" << i << ":" << j%i << " e " << resto(to_bit(j), to_bit(i)) << endl;
        } 
    }

    
}