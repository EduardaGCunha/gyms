#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

int main()
{
fastio;
  map<int, vector<int> > chng;
  chng[1] = {2, 5};
  chng[2] = {1, 3, 5, 6};
  chng[3] = {2, 4, 6, 7};
  chng[4] = {3, 7};
  chng[5] = {1, 2, 6, 8};
  chng[6] = {2, 3, 5, 7, 8, 9};
  chng[7] = {3, 4, 6, 9};
  chng[8] = {5, 6, 9, 10};
  chng[9] = {6, 7, 8, 10};
  chng[10] = {8, 9};

  vector<int> all_on = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  vector<int> original, copia, seq;
  int tam_min = 11;
  bool has_sol = false;

  for(int i=0 ;i<10 ; i++){
    int x; cin >> x;
    original.push_back(x);
  }

  for(int i=0 ; i<(1<<10) ; i++){
    if(has_sol && __builtin_popcount(i) > tam_min) continue;
    copia = original;
    vector<int> new_seq;
    for(int j=0 ; j<10 ; j++){
      if(i&(1<<j)){
        //cout << "bitON:" << j+1 << " troca:" ;
        for(auto u : chng[j+1]){
          //cout << copia[chng[j+1][k]-1] << " ";
          copia[u-1] = !(copia[u-1]);
        }
        new_seq.push_back(j+1);
        //cout << endl;
      }
    }
    //cout << "ficou:";
    //for (int w=0 ; w<10 ; cout << copia[w++] << " ");
    //cout << endl;

    bool ok = true;
    for(int i = 0; i < 10; i++){
        if (copia[i] == 0) { ok = false; break; }
    }
    if (!ok) continue;

    if(!has_sol){
        tam_min = new_seq.size();
        seq = new_seq;
        has_sol = true;
      }
      else{
        if(new_seq.size() <= tam_min && new_seq < seq){
          tam_min = new_seq.size();
          seq = new_seq;
        }
    }
  }

  if(has_sol){
    cout << tam_min << endl;
    for(int i=0 ; i<seq.size()-1; i++){
      cout << seq[i] << " ";
    }
    cout << seq[seq.size()-1] << endl;
  }
  else {
    cout << -1 << endl;
  }

}

