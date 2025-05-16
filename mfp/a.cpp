#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    if (n == 1) {
        cout << "a" << endl;
        return 0;
    }
    if (n == 2) {
        cout << "aba" << endl;
        return 0;
    }
    string s = "aba";
    for (int i = 2; i < n; ++i) {
        char current_char = 'a' + i;
        s = s + current_char + s;
        if (s.size() > 1e5) {
            s = s.substr(0, 1e5);
        }
        if (s.size() >= 1e5) {
            break;
        }
    }
    if (s.size() > 1e5) {
        s = s.substr(0, 1e5);
    }
    cout << s << endl;
    return 0;
}