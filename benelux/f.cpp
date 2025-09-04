#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n,c,menorPos;
    
    cin>>n>>c;
    vector<int>fila(n);
    vector<int>soma(n,0);
   
    for (int i = 0; i < n; i++)
    {
        cin>>fila[i];
        soma[i]+=fila[i];
    }
        
    int menor=LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        int cnt=0,posAtual=0,acu=0;
        int pos=soma[i]+1;
        while(acu<pos){
            int res=fila[i]-c;
            posAtual=fila[i+1]+res-c;
            acu+=posAtual+res;
            cnt++;
            i++;
    }
    if(cnt<menor){
        menorPos=i;
    }
}
    if(menor>=n){
        cout<<"impossible"<<endl;
    }
    else
    cout<<menorPos<<endl;
   
}