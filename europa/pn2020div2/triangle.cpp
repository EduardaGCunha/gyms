#include <bits/stdc++.h>
using namespace std;

int main(){
    int t1[3]; cin >> t1[0] >> t1[1] >> t1[2];
    sort(t1, t1+3);
    int t2[3]; cin >> t2[0] >> t2[1] >> t2[2];
    sort(t2, t2+3);
   
    if(t1[0]*t1[0] + t1[1]*t1[1] != t2[2]*t2[2]){
        cout << "NO\n";
        return 0;
    }
    if(t1[0] != t2[0] || t1[1] != t2[1] || t1[2] != t2[2] ){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

}