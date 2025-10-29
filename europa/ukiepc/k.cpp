#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+7;

signed main() {
    fastio;
    int total,k,p,qnt;
    cin>>total>>k>>p>>qnt;
    vector<int> v(qnt);
    vector<int> count(k+1, 0);
    for (int i = 0; i < qnt; i++){
        int x; cin>>x;
        v[i]=x;
        count[x]++;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= k; i++){
        pq.push({-count[i],i});   
    }

    int vezes = total-qnt;
    while(vezes--){
        auto [freq, numero] = pq.top(); pq.pop();
        v.push_back(numero);
        pq.push({freq-1, numero});
    } 
    vector<int> lst(MAXN, -1);
    for(int i = 0; i < total; i++){
        if(lst[v[i]] != -1 && (i - lst[v[i]]) < p){
            cout << "impossible\n";
            return 0;
        }
        lst[v[i]] = i;
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    

}