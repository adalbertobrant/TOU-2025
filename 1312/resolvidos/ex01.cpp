#include <bits/stdc++.h>

using namespace std;
// faça uma matriz de inteiros 3 x 3 em C++ que imprima os elementos de 1 a 9

int main() {
    // declaração da matriz de maneira estática
    int matriz[3][3];
    int numero = 0; // variável auxiliar que vai ser usada dentro do loop for
    // usuário entra os dados
    for ( int i = 0; i < 3; i++ ){
        for ( int j = 0; j < 3; j++ ){
            cout << "Entre o número " << (numero += 1) <<"° -> "; 
            cin >> matriz[i][j];
            // verifica se o número que foi digitado está correto
            if ( numero == matriz[i][j] ){
                continue; // uso do continue pois o número está correto
                }
            else {
                // enquanto o elemento matriz[i][j] não for igual ao numero, pede para o usuário preencher o número correto
                while ( numero != matriz[i][j] ){
                    cout << "Entre o número correto ->  " << numero << "-> "; 
                    cin >> matriz[i][j];
                }
            }
        }
    }
    // impressão na tela
    for ( int i = 0; i < 3; i++ ){
        for ( int j =0; j < 3; j++ ){
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }

	return 0;
}

