#include <bits/stdc++.h>

using namespace std;


int main() {


    int contadorChutes = 0;
    int entrada = 0;

    while( 1 ){ // condição de entrada no  laço -> sempre vai entrar pois 1 é verdadeiro lembar que o zero não é


        cin >> entrada; // entrada do número

        if (entrada == 2018) // se a entrada for 2018 executa a próxima linha que é o break
            break;

        contadorChutes++;
    }
    cout << contadorChutes << endl; // imprime o resultado 
                                    
	return 0; // retorna zero para a função main que é o código que tudo foi executado do jeito correto
}

