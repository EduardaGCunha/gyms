#include <bits/stdc++.h>
using namespace std;

char d1[] = {'*', '/', '+', '-'};

vector<string> expressoes(){
    vector<string> ans;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            for(int k = 0; k < 4; k++){
                string str = "";
                str += i + '0';
                str += + d1[k];
                str += j + '0';
                cout << str << endl;
                ans.push_back(str);
            }
        }
    }
    return ans;
}

int main(){
    vector<string> pos = expressoes();
    for(auto u : pos){
        cout << u << endl;
    }
    // for(auto u : pos){
    //     for(auto v : pos){
    //         for(int i = 0; i < 4; i++){
    //             string s;
    //             s += u;
    //             s += d1[i];
    //             s += v;
    //             cout << s << endl;
    //         }
    //     }
    // }
}