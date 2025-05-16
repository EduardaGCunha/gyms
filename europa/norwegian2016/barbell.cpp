#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int n, m, cur = 0;
int arr[MAXN], brr[MAXN];
set<int> st;

void fun(int l, int r, int idx){
    if(idx == m){
        if(l == r){
            for(int i = 0; i < n; i++) st.insert(l + r + arr[i]);
        }
        return;
    }

    fun(l, r, idx+1);
    fun(brr[idx] + l, r, idx + 1);
    fun(l, brr[idx] + r, idx + 1);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> brr[i];

    fun(0, 0, 0);

    for(auto u : st) cout << u << endl;

}