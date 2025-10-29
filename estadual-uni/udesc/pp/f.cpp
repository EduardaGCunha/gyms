#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, f, s; cin >> n >> f >> s;
    
    int arr[n], brr[n], pos[n+1]; 
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        cin >> brr[i];
        pos[brr[i]] = i; 
    }
    
    int ans = LLONG_MAX;
    int i = 0;
    while (i < n) {
        int lf = i;           
        int lr = pos[arr[i]];

        while (i < n && pos[arr[i]] == lr + (i - lf)) {
            //cout << "entrou no loop";
            //cout << i << " ";
            i++;
        }
        //cout << endl;
        //cout << lf << " " << lr << endl;
        int ef = i - 1; 
        int er = lr + (ef - lf); 

        //cout << ef << " " << er << endl;

        int ft = f * (lf + lr);            
        int st = s * (2 * n - ef - er - 2);     
        int tot = max(ft, st);
        //cout << ft << " " << st << " " << tot << endl;
        ans = min(ans, tot);
    }
    
    cout << ans << endl;
    
    return 0;
}