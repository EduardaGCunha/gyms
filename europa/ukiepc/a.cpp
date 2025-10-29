#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t; cin >> s >> t;
    map<int, int> freqs, freqt;
    int cnt[27];
    for(int i = 0; i < s.size(); i++){
        int v = s[i]-'a';
        freqs[v]++;
        cnt[v]++;
    }
    for(int i = 0; i < t.size(); i++){
        int v = t[i]-'a';
        freqt[v]++;
        cnt[v]++;
    }

    for(int i = 0; i < 26; i++){
        if(cnt[i]){
            int mx = max(freqs[i], freqt[i]);
            for(int j = 0; j < mx; j++){
                char a = i+'a';
                cout << a;
            }
        }
    }
    cout << endl;


}