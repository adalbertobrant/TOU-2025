#include <bits/stdc++.h>

using namespace std;

// verificar se uma matriz quadrada do teclado é identidade

int main() {
    int tam = 0; // armazena o tamanho da matriz
    cout << "Entre o tamanho da matriz quadrada -> ";
    cin >> tam;
    // verificação se a matriz é maior do que 1 senão pedir outro valor ao usuário
    while (tam <= 1){
        cout << "Tamanho da matriz deve ser maior do que " << tam << "\nEntre novo valor -> ";
        cin >> tam;
    }
    int matriz[tam][tam]; // tamanho da matriz definido pelo usuário

    // entrada de dados na matriz pelo usuário 
    for ( int i = 0; i < tam; i++ ){
        for ( int j = 0; j < tam; j++ ){
            cout << "Entre o " << ( i * tam ) + j + 1 << "° elemento da matriz[" << i << "][" << j << "] -> ";
            cin >> matriz[i][j];
        }
    }

    // verificação se a matriz quadrada digitada é identidade

    int flag = 1; // marcador flag (bandeira) se a matriz for identidade ele deverá sair do loop com valor 1

    for ( int i = 0; i < tam; i++ ){
        for ( int j = 0; j < tam; j++ ){

            if ( i == j ){
                if ( matriz[i][j] != 1 ){
                    flag = 0;
                    break; // sai do laço pois a condição está errada
                }
            }
            else {
                if ( matriz[i][j] != 0 ){
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 0)
            break; // para o laço for externo
        
    }
    if (flag){
        cout << "A matriz de tamanho " << tam << " é identidade" << endl;
        for ( int i = 0 ; i < tam; i++ ){
            for ( int j = 0; j < tam; j++ ) {
                cout << matriz[i][j] << "   ";
            }
            cout << endl;
        }
    }
    else{
        cout << "A matriz de tamanho " << tam << " não é identidade" << endl;
    }

	return 0;
}

