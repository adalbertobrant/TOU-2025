#include <bits/stdc++.h>

using namespace std;


int main() {

    int N, numeroAuxiliar;
    int contMulti2 = 0, contMulti3 = 0, contMulti4 = 0; // variáveis que vão guardar a quantidade de múltiplos 2, 3, e 4

    cin >> N; // qtd de números que Bino recebeu de presente

    for (int i = 0; i < N; i++){
        
        cin >> numeroAuxiliar; // entrada que vai pegar os números do Bino

        if ( numeroAuxiliar % 2 == 0 ) // verifica e conta os múltiplos de 2 
            contMulti2++; // contMulti2 = contMulti2 + 1

        if ( numeroAuxiliar % 3 == 0 ) // verifica e conta os múltiplos de 3.
            contMulti3++; // contMulti3 = contMulti3 + 1

        if ( numeroAuxiliar % 4 == 0 && numeroAuxiliar % 2 == 0 ) // verifica se é múltiplo de 2 e quatro
            contMulti4++; // contMulti4 = contMulti4 + 1
    }

    // imprime as linhas  
    cout << contMulti2 << endl;

    cout << contMulti3 << endl;

    cout << contMulti4 << endl;


	return 0;
}

