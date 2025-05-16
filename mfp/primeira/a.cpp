#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5);
int arr[MAXN];
int n, p;

//consigo alcancar esse tempo?
bool check(int mid){
    int sum =0;
    for(int i = 0; i < n; i++){
        sum += mid/arr[i];
        if(sum >= p) return true;
    }
    return sum >= p;
}

signed main(){
    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = 1e18;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << endl;
}