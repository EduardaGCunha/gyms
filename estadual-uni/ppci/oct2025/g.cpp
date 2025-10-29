#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

map<char, char> mp;
map<char, int> pos;

void setup(){
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['G'] = 'C';
    mp['C'] = 'G';

    pos['A'] = 0;
    pos['C'] = 1;
    pos['G'] = 2;
    pos['T'] = 3;
}

signed main() {
    fastio;
    setup();
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int x = k;
    string t = "ACGT";
    for(int i = 0; i < n; i++){
        //complementar
        char c = mp[s[i]];
        //cout << x << " " << " " << c << " " << pos[s[i]] << " ";
        x = (x^pos[s[i]]);
        //cout << x << endl;
        int r = (pos[c] + x)%4;
        cout << t[r];
        //cout << s[i] << " " << c << " " << x << " " << ((pos[c] + x)%4) << " " << t[r] << endl;
    }
    cout << endl;
}