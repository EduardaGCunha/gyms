#include <bits/stdc++.h>
using namespace std;

/*
aprovado: media > 70
entra em recuperacao: 40 < media < 69
reprovado: media < 40 
verdadeiro = numerico eh verdadeiro
falso = 0
*/

int main() {
    int media; cin >> media;

    if(media >= 70){
        cout << "Aluno aprovado!\n";
    }if(media >= 40 && media <= 69){
        cout << "Entra em recuperacao!\n";
    }if(media < 40){
        cout << "Reprovado\n";
    }

    // int x = 2;
    // if(){
    //     //printa q x  eh maior doq 2
    // }else if( x < 2){
    //     //printo q x eh menor doq 2
    // }else if(){

    /*
    maior
    igual
    menor
    */
    // int random = rand()%100;
    // int x = 0;
    // while(x != random){
    //     if(x > random){
    //         x/=2; 
    //     }
    // }

}