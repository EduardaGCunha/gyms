#include <bits/stdc++.h>
using namespace std;

bool eh_primo(int x){
	int qtd = 0;
    for(int i = 2; i <= x; i++){
        if((x%i) == 0){
            qtd++;
        }
    }
    return (qtd == 1);
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S" << "\n";
	}else{
		cout << "N" << "\n";
	}
}