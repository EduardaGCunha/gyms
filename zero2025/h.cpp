#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

/*
divide ele no meio e espelha a primeira parte
se essa parte for maior q o número original, ai tiro o digito menos significativo
e refaço
*/

string conversorS(int x) {
    string s;
    while (x > 0) {
       char a = ('0' + (x&1));
        s += a;
        x /=2;
    }
    reverse(s.begin(), s.end());
    //cout << 
    return s;
}

int conversorI(string s){
    int res = 0;
    for(int i = 0; i < (int)s.size(); i++){
        res = (res << 1) + (s[i] - '0');
    }
    //cout << res << endl;
    return res;
}

string palindrome(string str, int impar, char mid){
    string t = str;
    if(impar) t += mid;
    string meio = t;
    reverse(t.begin(), t.end());
    meio += t;
    return meio;
}

string decrement(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if (i < 0) return "";
    s[i] = '0';
    if (s[0] == '0')  return string(s.size() - 1, '1');
    return s;
}

signed main() {
    fastio;
    int n; cin >> n;

    //pode ser q seja 0 nao sei
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }

    string pt1 = conversorS(n);
    int l = pt1.size();
    int pfxlen = (l + 1) / 2;

    //calcula pfx rapido
    string pfx = pt1.substr(0, pfxlen);
    int tame = pfxlen - (l % 2);
    
    //pega o espelho
    string espelho = pfx.substr(0, tame);
    reverse(espelho.begin(), espelho.end());

    string str = pfx + espelho;
    int x = conversorI(str);

    if (x <= n) {
        cout << x << endl;
        return 0;
    }

    string novo = decrement(pfx);
    //cout << novo << endl;
    if (novo.empty() || novo.size() < pfxlen) {
        if (l == 1)  cout << 0 << endl;
        else  cout << ((1LL << (l-1)) -1) << endl;
        return 0;
    }

    espelho = novo.substr(0, tame);
    reverse(espelho.begin(), espelho.end());
    string new_str = novo + espelho;
    int res = conversorI(new_str);

    if (res <= n) {
        cout << res << endl;
    } else {
        cout << ((1LL << (l-1)) -1) << endl;
    }

    return 0;
}