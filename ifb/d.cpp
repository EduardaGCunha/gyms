#include <bits/stdc++.h>
using namespace std;

bool check(string t){
    string s = t;
    for(int i = 0; i < t.size(); i++){
        s[i] = tolower(s[i]);
    }

    if(s == "daniel") return true;
    return false;
}

/* faco uma funcao p checar se eh daniel sad aquela substring 
    do contrario
    se for, eu vou ajustar a caixa novamente e retornar consertado
    nesse retorno, ajusto j para ser +8 caracteres e continuo o loop
outro loop p adicionar os caracteres restantes caso j < n ainda
*/

int main(){
    string s; 
    getline(cin, s);
    //cout << s << endl;
    int i = 0, j = 6, n = s.size();
    string ans = "";
    while(j <= n){
        //cout << j << endl;
        string str = s.substr(i, j);
        //cout << str << endl;
        if(check(str)){
            int x = j;
            string t = "";
            while(x < n && isalpha(x)){
                t[i] 
            }
            cout << s.substr(j+1, x) << endl;
            i++, j++;
        }else{
            i++;
            j++;
        }
        ans += s[i];
    }

    if(j > n){
        while(i++ <= n) ans += s[i];
    }
    cout << ans << endl;
}