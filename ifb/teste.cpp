#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl "\n"

vector<ll>parent;
vector<pair<ll,ll>>edges;
vector<string>querys;

ll find(ll x){
    if(parent[x]<0)return x;
    return parent[x]=find(parent[x]);
}

void unite(ll x,ll y){
    if(x==y)return;
    if (x<=y){
        parent[x]+=parent[y];
        parent[y]=x;
    }else{
        parent[y]+=parent[x];
        parent[x]=y;
    }
    
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    parent.resize(n+1,-1);
    edges.resize(k+1);
    querys.resize(k+1);


    for (ll i = 0; i < m; i++){
        ll a,b;
        cin>>a>>b;
    }

    for (ll i = 0; i < k; i++){
        cin>>querys[i]>>edges[i].first>>edges[i].second;
    }

    vector<string> ans;
    for (ll i = k-1; i >= 0; i--) {
        if(querys[i] != "ask"){
            unite(find(edges[i].first), find(edges[i].second));
        }else{ 
            if(find(edges[i].first) != find(edges[i].second)){
                ans.push_back("YES");
            }else ans.push_back("NO");
            //cout<<(find(edges[i].first)!=find(edges[i].second)?"YES":"NO")<<endl;
        }
    }
    
    //reverse(ans.begin(), ans.end());
    for(auto u : ans){
        cout << u << endl;
    }

    return 0;
}

