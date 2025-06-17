#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> lst(26, -1);
    for(int i = 0; i < n; i++){
        lst[s[i]-'a'] = i;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < (s[i]-'a'); j++){
            if(lst[j] > i){
                int x = lst[j];
                swap(s[i], s[x]);
                cout << s << endl;
                return 0;
            }
        }
    }

    cout << s << endl;
}