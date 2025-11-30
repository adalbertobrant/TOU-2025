#include <bits/stdc++.h>

using namespace std;


int main() {

    int N ; // quantidade de tipos de balas diferentes que a SBC (Super Balas e Caramelos) produz
    
    int aux = 9999999; // número inteiro bem grande para servir de comparação inicial

    cin >> N; // entrada da quantidade de balas diferentes produzidas pela SBC

    for (int i = 0; i < N; i++){ // loop de interação 
        int balas; // variável auxiliar balas 
        
        cin >> balas; // entrada 

        if (balas == 0){ // se a bala é zero Algo não tem o papel daquela bala e não pode enviar envelopes
            cout << balas << endl;
            return 0; // termina o programa 
        }
        
        if ( balas < aux){ // verifica a quantidade de envelopes a ser enviada pois é a mesma da menor quantidade de balas 
            aux = balas; // variável aux recebe a qtd de balas
        }
    }

    cout << aux << endl; // imprime na tela os envelopes a serem enviados

	return 0;
}

