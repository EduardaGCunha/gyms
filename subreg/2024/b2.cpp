#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

const int MAXN = 207, MAXM = 1e6+7;
vector<int> movies_to_people[MAXN];
//pessoa pra filme
bool people_to_movies[MAXM][MAXN];
int visited[MAXN], comp[MAXN];
int n;

/*
I need a way to create this graph
For each movie, I know who connects to it 
Then I do a DFS starting from the first movie
I go over the people that connect to this movie and check their other connections 
if they connect to a new movie, then I create an edge between them
*/

vector<pair<int, int>> graph[MAXN];

//creating the graph
void dfs(int m, int c){
    comp[m] = c;
    visited[m] = 1;
    //p cada pessoa conectada nesse filme
    for(auto p : movies_to_people[m]){
        //quais sao os filmes q ela se conecta?
        for(int f = 1; f <= n; f++){
            //esse filme ja foi visitado? se nao, entao posso colocar esse ator como um intermediario
            //que conecta esses filmes
            if(!visited[f] && people_to_movies[p][f]){
                //o filme m se conecta com o f atraves do ator u
                graph[m].push_back({f, p});
                graph[f].push_back({m, p});
                dfs(f, c);
            }
        }
    }
}

vector<int> ans;
int cnt = 0;

int dfs2(int v, int y){
    visited[v] = 1;
    if(people_to_movies[y][v]){
        ans.push_back(y);
        cnt++;
        //cout << y << endl;
        return 1;
    }

    for(auto [f, u] : graph[v]){
        if(!visited[f] && dfs2(f, y)){
            ans.push_back(f);
            ans.push_back(u);
            cnt++;
            //cout << u << " " << f << endl;
            return 1;
        }
    }
    return 0;
}


signed main() {
    fastio;
    int m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        while(k--){
            int x; cin >> x;
            movies_to_people[i].push_back(x);
            //pessoa x se conecta com o filme i
            people_to_movies[x][i] = 1;
        }
    }

    int c = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            c++;
            dfs(i, c);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << "o filme " << i << ": " << endl;
        for(auto u : graph[i]){
            cout << "se conecta com o filme " << u.first << " atraves do ator " << u.second << endl;
        }
        cout << endl;
    }

    // for(int i = 1; i <= m; i++){
    //     cout << "conexoes da pessoa " << i << ": ";
    //     for(int f = 1; f <= n; f++){
    //         if(people_to_movies[i][f]) cout << f << " ";
    //     }
    //     cout << endl;
    // }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cnt = 0;
        int pos = 0;
        for(int f = 1; f <= n; f++){
            ans.clear();
            for(int i = 1; i < MAXN; i++) visited[i] = 0;
            //se essa pessoa x se conecta com o filme f e existe um caminho entre o f e a pessoa y
            if(people_to_movies[x][f] && dfs2(f, y)){
                pos = 1;
                cnt++;
                ans.push_back(f);
                ans.push_back(x);
                break;
            }
        }

        if(!pos){
            cout << -1 << endl;
        }else{
            reverse(ans.begin(), ans.end());
            cout << cnt << endl;
            for(auto u : ans){
                cout << u << " ";
            }
            cout << endl;
        }
    }
}