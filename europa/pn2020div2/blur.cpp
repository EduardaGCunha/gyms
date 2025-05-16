//trick bem legal para essa questao: colocar todo um para ser 9^9, pq assim toda divisao vai ser divisivel por 9
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 101;
int grid[MAXN][MAXN], temp[MAXN][MAXN];

signed main(){
    int w, h, b;
    cin >> h >> w >> b;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            int x; cin >> x;
            if(x == 1) grid[i][j] = 387420489;
            else grid[i][j] = 0;
        }
    }

    int cnt = 0;
    //-1, 0, 1
    while(b--){
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                int sum = 0;
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy++){
                        //(b + (a % b)) % b
                        int nx = (i+dx+w)%w;
                        int ny = (j+dy+h)%h;
                        //if(i == 0 && j == 0) cout << nx << " " << ny << endl;
                        sum += grid[nx][ny];
                    }
                }
                temp[i][j] = sum/9;
            }
        }

        set<int> st;
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                st.insert(temp[i][j]);
                grid[i][j] = temp[i][j];
            }
            //cout << endl;
        }
        cnt = st.size();
    }

    cout << cnt << endl;
}