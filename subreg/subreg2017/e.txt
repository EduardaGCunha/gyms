#include <bits/stdc++.h>
using namespace std;


int main(){
    
    vector<set<int>> v(12);
    vector<int> ordem = {0, 2, 4, 5, 7, 9, 11};
    for(int i = 0; i < 12; i++){
        for(auto u : ordem){
            v[i].insert((u+i)%12);
        }
    }

    int n; cin >> n;
    set<int> st; 
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert((x-1)%12);
    }

    vector<string> mp = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol",  "sol#",  "la",  "la#",  "si"};

    string ans = "desafinado";
    for(int i = 0; i < 12; i++){
        int pos = 1;
        for(auto u : st){
            if(v[i].find(u) == v[i].end()) pos = 0;
        }
        if(pos){    
            ans = mp[i];
            break;
        }
    }

    cout << ans << endl;

}