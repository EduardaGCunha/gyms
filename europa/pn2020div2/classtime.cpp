#include <bits/stdc++.h>
using namespace std;

struct st{
    string a;
    string b;
    bool operator<(const st &other){
        if(b == other.b) return a < other.a;
        return b < other.b;
    }
};

int main(){
    int n; cin >> n;
    vector<st> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i].a >> vec[i].b;
    }

    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        cout << vec[i].a << " " << vec[i].b << endl;
    }
}