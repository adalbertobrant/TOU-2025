#include <bits/stdc++.h>

using namespace std;


int main() {


    string texto = "Fatorial do numero" ;
    cout << texto << endl;
    int numero, acumulador = 1;
    cout << "Digite o numero -> ";
    cin >> numero;
    
    // cálculo do fatorial
    for ( int i = 1; i <= numero; i++ ) {
        acumulador *= i;
    }

    // mostra na tela o fatorial do número
    cout << texto << " " << numero << "! -> " << acumulador << endl; 


	return 0;
}

