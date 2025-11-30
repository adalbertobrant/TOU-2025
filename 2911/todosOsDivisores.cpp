#include <bits/stdc++.h>

using namespace std;


int main() {

    int X; // declaração da variável X

    cin >> X; // entrada para X
    
    for ( int i = 1 ; i <= X ; i++ ){ // laço for iniciando em com i igual a 1 pois X/0 é indeterminado
        if ( X % i == 0 ) { // condição de verificação dos divisores para o número X
            cout << i << " "; // imprime segundo as normas do exercício
        }
    }

	return 0;
}

