#include <bits/stdc++.h>

using namespace std;


int main() {

    // o problema do buffer de teclado
    // Ao entramos com dados via teclado , existe o problema de algo ficar para trás devido ao nosso tipo de dados 
    // o sinal '\n' indica quebra de linha e ao digitar o 'enter' nos editores é considerado dar esse sinal

    int x = 10;
    int k = 20;
    char letra, letra2;

    cout << "valor de x ->  " << x << endl;
    cout << "valor de k ->  " << k << endl;
    
    cin >> x;
    cin >> letra;
    cin >> letra2;
    cin >> k;

    cout << "letra digitada foi ->  " << letra << endl;
    cout << "valor de x ->  " << x << endl;
    cout << "valor de k ->  " << k << endl;
    cout << "letra digitada foi ->  " << letra2 << endl;


    char letra_x = 'x';
    char letra_k = 'k';


    cout << letra_x << endl;
    cout << letra_k << endl;

	return 0;
}

