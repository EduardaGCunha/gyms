#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n; cin >> n;
    if(n == 1){
        cout << "a" << endl;
        return 0;
    }
    if(n == 2){
        cout << "aba" << endl;
        return 0;
    }
    string s = "aba";
    for(int i = 2; i < n; i++){
        char a = 'a' + i;
        s = s + a + s;
        if(s.size() > 1e5){
            string t = "";
            while(t.size() <= 1e5){
                t += s[i];
            }
            s = t;
            break;
        }
    }
    cout << s << endl;
}