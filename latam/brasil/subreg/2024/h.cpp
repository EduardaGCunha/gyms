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
    string s, t; cin >> s >> t;
    vector<int> asc_s;
    vector<int> asc_t;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='*') asc_s.push_back(i);
    }
    for(int i=0 ; i<t.size() ; i++){
        if(t[i]=='*') asc_t.push_back(i);
    }
    int qtd = asc_s.size() + asc_t.size();
    //cout << "qtd " << qtd << endl;
 
    for(int i = 0; i < (1<<qtd); i++){
        for(int j=0 ; j<qtd ; j++){
            //cout << ((i&(1<<j))!=0) ;
            if(j<asc_s.size()){
                s[asc_s[j]] = '0' + (((i&(1<<j))!=0));
            }
            else{
                t[asc_t[j - asc_s.size()]] =  '0' + ((i&(1<<j))!=0);
            }
        }
        //cout << " testando " << s << "(" << to_int(s) << ") e " << t << "(" << to_int(t) << ") = " << to_int(s)%to_int(t) << endl; 
        if(resto(s, t)==0){
            cout << s << endl;
            return 0;
        }

    }
}