#include <bits/stdc++.h>

using namespace std;


int main() {

    char frase[] = {"passando a frase"};
    char frase1[] = {"passando"};
    char frase2[] = {" a "};
    char frase3[] = {"frase"};
    string soma = frase1 + frase2 + frase3;

    for (int i = 0 ; i < 3; i++ ) {
        char aux;
        aux = frase[i];
        cout << aux << endl;
    }
    cout << frase << endl;
    cout << "soma das frases " << endl;
    cout << soma << endl;

	return 0;
}

