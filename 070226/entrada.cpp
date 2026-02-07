#include <bits/stdc++.h>

using namespace std;


int main() {
    string frase;
    cout << " Digite a frase " << endl;
//    cin >> frase; // oi + enter
//    cout << frase << endl; // oi
//    cin.ignore();
//    cout << " Digite a frase " << endl;
//    cin.ignore();
//
// desafio buffer do teclado em cpp , cin.ignore(), NULL, char , 1 byte de tamanho.
//
//    getline(cin, frase); // \n
//    cout << frase << endl;
//    cout << " Digite a frase " << endl;
//    getline(cin, frase); // \n
//    cout << frase << endl;
    getline(cin, frase);

    int tamanho = frase.size();
    cout << "frase.size() -> " << tamanho << endl;

    int tam = size(frase);
    cout << "size(frase) -> " << tam << endl;


	return 0;
}

